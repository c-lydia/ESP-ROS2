import math

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Imu
from sensor_msgs.msg import Range
from custom_interfaces.msg import Gamepad


class RobotControl(Node):
    def __init__(self):
        super().__init__('robot_control_node')

        self.declare_parameter('max_linear_speed', 0.6)
        self.declare_parameter('max_angular_speed', 1.5)
        self.declare_parameter('deadband', 0.08)
        self.declare_parameter('publish_rate_hz', 20.0)
        self.declare_parameter('range_stop_enabled', True)
        self.declare_parameter('min_clearance_m', 0.25)
        self.declare_parameter('enable_button', 'lb')
        self.declare_parameter('pi_mode_button', 'a')
        self.declare_parameter('range_kp', 1.2)
        self.declare_parameter('range_ki', 0.2)
        self.declare_parameter('yaw_kp', 2.0)
        self.declare_parameter('yaw_ki', 0.2)
        self.declare_parameter('integral_limit_linear', 0.8)
        self.declare_parameter('integral_limit_angular', 1.0)

        self.max_linear_speed = float(self.get_parameter('max_linear_speed').value)
        self.max_angular_speed = float(self.get_parameter('max_angular_speed').value)
        self.deadband = float(self.get_parameter('deadband').value)
        self.publish_rate_hz = float(self.get_parameter('publish_rate_hz').value)
        self.range_stop_enabled = bool(self.get_parameter('range_stop_enabled').value)
        self.min_clearance_m = float(self.get_parameter('min_clearance_m').value)
        self.enable_button = str(self.get_parameter('enable_button').value).strip()
        self.pi_mode_button = str(self.get_parameter('pi_mode_button').value).strip()
        self.range_kp = float(self.get_parameter('range_kp').value)
        self.range_ki = float(self.get_parameter('range_ki').value)
        self.yaw_kp = float(self.get_parameter('yaw_kp').value)
        self.yaw_ki = float(self.get_parameter('yaw_ki').value)
        self.integral_limit_linear = float(self.get_parameter('integral_limit_linear').value)
        self.integral_limit_angular = float(self.get_parameter('integral_limit_angular').value)

        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.gamepad_sub = self.create_subscription(Gamepad, '/gamepad', self.gamepad_callback, 10)
        self.range_sub = self.create_subscription(Range, '/range/filter', self.range_callback, 10)
        self.imu_sub = self.create_subscription(Imu, '/imu/filter', self.imu_callback, 10)

        self._latest_gamepad = None
        self._latest_range_m = None
        self._latest_yaw_rad = None
        self._last_cmd = Twist()
        self._target_range_m = None
        self._target_yaw_rad = None
        self._range_integral = 0.0
        self._yaw_integral = 0.0
        self._pi_mode_active = False
        self._prev_pi_button = False
        self._last_timer_time = self.get_clock().now()

        timer_period = 1.0 / self.publish_rate_hz if self.publish_rate_hz > 0.0 else 0.05
        self.timer = self.create_timer(timer_period, self.timer_callback)

        self.get_logger().info('Robot control node started')

    @staticmethod
    def _apply_deadband(value: float, deadband: float) -> float:
        if abs(value) < deadband:
            return 0.0
        return value

    def _is_enable_pressed(self, msg: Gamepad) -> bool:
        return self._is_button_pressed(msg, self.enable_button)

    @staticmethod
    def _wrap_angle_rad(angle: float) -> float:
        return math.atan2(math.sin(angle), math.cos(angle))

    @staticmethod
    def _quat_to_yaw_rad(x: float, y: float, z: float, w: float) -> float:
        siny_cosp = 2.0 * (w * z + x * y)
        cosy_cosp = 1.0 - 2.0 * (y * y + z * z)
        return math.atan2(siny_cosp, cosy_cosp)

    @staticmethod
    def _clamp(value: float, min_value: float, max_value: float) -> float:
        return max(min_value, min(max_value, value))

    def _is_button_pressed(self, msg: Gamepad, button_name: str) -> bool:
        if button_name == 'a':
            return bool(msg.a)
        if button_name == 'b':
            return bool(msg.b)
        if button_name == 'x':
            return bool(msg.x)
        if button_name == 'y':
            return bool(msg.y)
        if button_name == 'lb':
            return bool(msg.lb)
        if button_name == 'rb':
            return bool(msg.rb)
        if button_name == 'back':
            return bool(msg.back)
        if button_name == 'start':
            return bool(msg.start)
        if button_name == 'home':
            return bool(msg.home)
        if button_name == 'left_stick_press':
            return bool(msg.left_stick_press)
        if button_name == 'right_stick_press':
            return bool(msg.right_stick_press)
        return False

    def _reset_pi_state(self):
        self._range_integral = 0.0
        self._yaw_integral = 0.0
        self._target_range_m = None
        self._target_yaw_rad = None
        self._pi_mode_active = False

    def _maybe_update_pi_mode(self, msg: Gamepad):
        pi_pressed = self._is_button_pressed(msg, self.pi_mode_button)
        rising_edge = pi_pressed and not self._prev_pi_button
        self._prev_pi_button = pi_pressed

        if not pi_pressed:
            if self._pi_mode_active:
                self._reset_pi_state()
            return

        if rising_edge:
            if self._latest_range_m is not None and self._latest_yaw_rad is not None:
                self._target_range_m = self._latest_range_m
                self._target_yaw_rad = self._latest_yaw_rad
                self._range_integral = 0.0
                self._yaw_integral = 0.0
                self._pi_mode_active = True
                self.get_logger().info(
                    f'PI mode engaged: target_range={self._target_range_m:.3f} m, target_yaw={self._target_yaw_rad:.3f} rad'
                )

    def _compute_pi_cmd(self, dt: float) -> Twist:
        cmd = Twist()
        if not self._pi_mode_active:
            return cmd
        if self._target_range_m is None or self._target_yaw_rad is None:
            return cmd
        if self._latest_range_m is None or self._latest_yaw_rad is None:
            return cmd

        range_error = self._target_range_m - self._latest_range_m
        yaw_error = self._wrap_angle_rad(self._target_yaw_rad - self._latest_yaw_rad)

        self._range_integral += range_error * dt
        self._yaw_integral += yaw_error * dt

        self._range_integral = self._clamp(
            self._range_integral,
            -self.integral_limit_linear,
            self.integral_limit_linear,
        )
        self._yaw_integral = self._clamp(
            self._yaw_integral,
            -self.integral_limit_angular,
            self.integral_limit_angular,
        )

        linear_cmd = self.range_kp * range_error + self.range_ki * self._range_integral
        angular_cmd = self.yaw_kp * yaw_error + self.yaw_ki * self._yaw_integral

        cmd.linear.x = self._clamp(linear_cmd, -self.max_linear_speed, self.max_linear_speed)
        cmd.angular.z = self._clamp(angular_cmd, -self.max_angular_speed, self.max_angular_speed)
        return cmd

    def _range_allows_motion(self) -> bool:
        if not self.range_stop_enabled:
            return True
        if self._latest_range_m is None:
            return True
        if not math.isfinite(self._latest_range_m):
            return True
        return self._latest_range_m >= self.min_clearance_m

    def gamepad_callback(self, msg: Gamepad):
        self._latest_gamepad = msg
        self._maybe_update_pi_mode(msg)

        if not self._is_enable_pressed(msg):
            self._reset_pi_state()
            self._last_cmd = Twist()
            return

        linear_input = self._apply_deadband(-float(msg.left_stick_y), self.deadband)
        angular_input = self._apply_deadband(float(msg.left_stick_x), self.deadband)

        dt = (self.get_clock().now() - self._last_timer_time).nanoseconds * 1e-9
        dt = self._clamp(dt, 0.0, 0.2)

        if self._pi_mode_active:
            cmd = self._compute_pi_cmd(dt)
        else:
            cmd = Twist()
            cmd.linear.x = max(-1.0, min(1.0, linear_input)) * self.max_linear_speed
            cmd.angular.z = max(-1.0, min(1.0, angular_input)) * self.max_angular_speed

        if not self._range_allows_motion():
            cmd.linear.x = 0.0
            cmd.angular.z = 0.0
            self.get_logger().warn(
                f'Range stop active: latest_range={self._latest_range_m:.3f} m < min_clearance_m={self.min_clearance_m:.3f} m'
            )

        self._last_cmd = cmd

    def range_callback(self, msg: Range):
        if math.isfinite(msg.range):
            self._latest_range_m = float(msg.range)

    def imu_callback(self, msg: Imu):
        q = msg.orientation
        self._latest_yaw_rad = self._quat_to_yaw_rad(q.x, q.y, q.z, q.w)

    def timer_callback(self):
        self._last_timer_time = self.get_clock().now()
        self.cmd_vel_pub.publish(self._last_cmd)
        self.get_logger().info(f'Publishing: {self._last_cmd}')

def main(args=None):
    rclpy.init(args=args)
    node = RobotControl()

    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
