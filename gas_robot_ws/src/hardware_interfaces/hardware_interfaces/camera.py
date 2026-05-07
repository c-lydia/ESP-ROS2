import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
from cv_bridge import CvBridge
import cv2 as cv

class Camera(Node):
    def __init__(self):
        super().__init__('camera_node')
        self.camera_cal_pub = self.create_publisher(CameraInfo, '/camera/camera_info', 10)
        self.image_raw_pub = self.create_publisher(Image, '/camera/image_raw', 10)
        self.timer = self.create_timer(1.0/30.0, self.timer_callback)
        self.bridge = CvBridge()
        self.capture = cv.VideoCapture(0)
        self.get_logger().info('Camera node started')
        
    def timer_callback(self):
        ret, frame = self.capture.read()
        
        if not ret:
            return
        
        img_msg = self.bridge.cv2_to_imgmsg(frame, encoding = 'bgr8')
        img_msg.header.stamp = self.get_clock().now().to_msg()
        img_msg.header.frame_id = 'camera_link'
        
        self.image_raw_pub.publish(img_msg)
        
        info_msg = CameraInfo()
        info_msg.header = img_msg.header
        info_msg.width = frame.shape[0]
        info_msg.height = frame.shape[0]
        info_msg.k = [1.0, 0.0, frame.shape[1]/2,
                  0.0, 1.0, frame.shape[0]/2,
                  0.0, 0.0, 1.0]
        
        self.camera_cal_pub.publish(info_msg)
        
def main():
    rclpy.init()
    camera_node = Camera()
    rclpy.spin(camera_node)
    camera_node.destroy_node()
    rclpy.shutdown()
    
if __name__ == '__main__':
    main()