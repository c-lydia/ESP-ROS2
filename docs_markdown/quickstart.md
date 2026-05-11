# Quick Start

This guide gets a robot system running end-to-end with minimal setup. It assumes you already have the repository cloned and Docker installed.

If you’re new, read `intro.md` first.

## System Requirements

Make sure your machine has:

- Docker + Docker Compose
- ROS 2 Humble (inside container recommended)
- Python 3.10+
- Git
- USB access (for ESP32 flashing, if needed)

Optional but useful:

- VS Code
- ROS 2 CLI tools installed locally

## Clone the Workspace

```bash
git clone <your-repo-url>
cd micro_ros_ws
```

## Start the Development Environment

Most development happens inside Docker:

``` bash
docker compose up -d
```

This starts:

- ROS 2 workspace container
- micro-ROS agent container

## Verify ROS 2 is Running

Enter the container:

``` bash
docker exec -it ros2_ws bash
```

Check ROS 2:

``` bash
ros2 topic list
```

You should see base system topics like:

``` bash
/rosout
/parameter_events
```

## Start micro-ROS Agent

If not already running:

``` bash
ros2 run micro_ros_agent micro_ros_agent udp4 --port 8888
```

You should see:

``` bash
waiting for a micro-ROS agent client...
```

## Flash ESP32 Firmware (if needed)

Navigate to firmware:

``` bash
cd firmware/esp32_controller
```

Build:

``` bash
idf.py build
```

Flash:

``` bash
idf.py -p /dev/ttyUSB0 flash monitor
```

## Confirm Robot Connection

Once firmware boots, check agent logs:

You should see something like:

``` bash
New client connected from <ip>:<port>
```

Now verify sensor topics:

``` bash
ros2 topic list
```

Expected:

``` bash
/imu/data
/range/front
/odom
```

## Test Motion Control

Publish a test velocity command:

``` bash
ros2 topic pub /cmd_vel geometry_msgs/msg/Twist \
"{linear: {x: 0.1}, angular: {z: 0.0}}"
```

Robot should move forward slowly.

Stop it:

``` bash
ros2 topic pub /cmd_vel geometry_msgs/msg/Twist \
"{linear: {x: 0.0}, angular: {z: 0.0}}"
```

##  Verify Sensor Output

IMU:

``` bash
ros2 topic echo /imu/data
```

Range sensor:

``` bash
ros2 topic echo /range/front
```

Odometry:

``` bash
ros2 topic echo /odom
```

## Launch Visualization (Optional)

If RViz is configured:

``` bash
ros2 launch visualization display.launch.py
```

You should see:

- robot pose
- TF tree
- sensor overlays

## Run a Robot Variant

### Wall-E (manual mode)

``` bash
ros2 launch wall_e bringup.launch.py
```

### Gas Robot (autonomous mode)

``` bash
ros2 launch gas_robot bringup.launch.py
```

## Common Issues

### No topics appear

- Check micro-ROS agent is running
- Check ESP32 WiFi connection

### Robot not moving

- Verify `/cmd_vel` is being published
- Check motor driver power

### ESP32 not connecting

- Ensure same network
- Check firewall / port 8888

## Next Steps

Once everything is running:

- `platform/system_contract.md` → understand message rules
- `ros2/topics.md` → learn communication layer
- `variants/wall_e/index.md` → first full robot system
