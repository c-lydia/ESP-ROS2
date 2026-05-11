.. _communication_model:

====================
Communication Model
====================

Overview
========

The communication model defines how data flows between the ESP32 firmware, the ROS 2 host system, and individual subsystems. The architecture uses multiple layers of abstraction to enable reliable, distributed communication.

Communication Layers
====================

::

    Layer 4: ROS 2 Application Nodes
    (Wall-E, Gas Robot, Subsystems)
           ↓ DDS Middleware
    Layer 3: ROS 2 Topic/Service Bus
           ↓ micro-ROS Serialization
    Layer 2: micro-ROS Agent Bridge
           ↓ UDP/TCP
    Layer 1: Firmware (ESP32)

Layer 1: Firmware (ESP32)
-------------------------

The ESP32 runs FreeRTOS with embedded micro-ROS client libraries:

- **Subsystem Tasks**: Sensor polling, motor control (FreeRTOS tasks)
- **micro-ROS Node**: Embedded ROS 2 node running on firmware
- **Network**: Connects to ROS 2 via UDP or TCP

The firmware communicates exclusively through micro-ROS:
- Publications: Sensor data and status
- Subscriptions: Commands from ROS 2

Layer 2: micro-ROS Agent
------------------------

The micro-ROS agent acts as a bridge between the firmware and ROS 2 host:

- **Runs on**: Docker container or native Linux machine
- **Port**: Default UDP 8888 or TCP 9999
- **Function**: Translates micro-ROS ↔ DDS messages
- **Discovery**: Automatically finds firmware on network

Launch the agent:

::

    ros2 run micro_ros_agent micro_ros_agent [udp4 --port 8888 | tcp4 --port 9999]

Layer 3: ROS 2 Topic/Service Bus
--------------------------------

ROS 2 uses DDS (Data Distribution Service) for pub/sub:

- **Publish**: Nodes advertise topics, others subscribe
- **Subscribe**: Receive data from publishers
- **Services**: Request/response communication
- **Middleware**: Cyclone DDS (default) or others

Topics are the primary communication mechanism.

Layer 4: Application Nodes
---------------------------

Individual ROS 2 nodes implement the robot's logic:

- **Perception Nodes**: Process sensor data
- **Planning Nodes**: Compute paths and commands
- **Control Nodes**: Execute motor commands
- **Navigation Nodes**: Autonomous movement

Message Flow Examples
======================

Sensor Data Flow
----------------

::

    Firmware Task (IMU polling)
            ↓
    micro-ROS Publish /imu/data
            ↓
    Agent translates to DDS
            ↓
    Host ROS 2 nodes subscribe /imu/data
            ↓
    Application processes IMU

Motor Command Flow
-------------------

::

    Application publishes /cmd_vel
            ↓
    DDS propagates to subscribers
            ↓
    Firmware micro-ROS subscriber receives
            ↓
    Control task executes motors

Message Types
=============

Standard ROS 2 Messages
-----------------------

Used for common robotics data:

.. list-table::
   :header-rows: 1
   :widths: 30 50

   * - Message Type
     - Purpose
   * - ``geometry_msgs/Twist``
     - Velocity commands (linear + angular)
   * - ``sensor_msgs/Imu``
     - Inertial measurement data
   * - ``sensor_msgs/Range``
     - Distance sensor reading
   * - ``nav_msgs/Odometry``
     - Position and velocity estimate
   * - ``tf2_msgs/TFMessage``
     - Coordinate frame transformations

Custom Messages
---------------

Defined in ``custom_interfaces/msg/``:

- Robot configuration
- Status information
- Gas sensor readings (Gas Robot)
- Custom sensor types

Define custom message:

::

    # custom_interfaces/msg/CustomData.msg
    int32 field1
    float64 field2
    string description

Quality of Service (QoS)
=========================

Different communication patterns use appropriate QoS policies:

Sensor Data (Best-Effort, Latest-Only)
---------------------------------------

Fast-updating sensor streams:

::

    Publisher:
      QoS: Best-Effort, History: Keep Last (size 1)
      
    Subscriber:
      QoS: Best-Effort, History: Keep Last (size 1)

**When to use**: High-frequency data where packets can be lost
**Example**: IMU, camera streams, odometry

Commands (Reliable, Keep Last)
------------------------------

Important commands that must arrive:

::

    Publisher:
      QoS: Reliable, History: Keep Last (size 10)
      
    Subscriber:
      QoS: Reliable, History: Keep Last (size 10)

**When to use**: Motor commands, navigation goals, configuration changes

Configuration (Reliable, Keep All)
----------------------------------

Configuration that must never be lost:

::

    Publisher:
      QoS: Reliable, History: Keep All
      
    Subscriber:
      QoS: Reliable, History: Keep All

**When to use**: Initial parameters, one-time setup messages

Network Configuration
======================

Connection Setup
----------------

**IP Address**: ROS 2 host IP or hostname
**Port**: 
  - UDP: 8888 (default, recommended)
  - TCP: 9999 (for unreliable networks)

Configure firmware for your host:

::

    ros2 run micro_ros_setup configure_firmware.sh esp32_controller \
      --transport udp \
      --ip 192.168.1.100 \
      --port 8888

Multi-Robot Setup
------------------

Use different ``ROS_DOMAIN_ID`` for multiple robots:

::

    # Robot 1 (default)
    export ROS_DOMAIN_ID=0
    ros2 launch wall_e.launch.py
    
    # Robot 2
    export ROS_DOMAIN_ID=1
    ros2 launch gas_robot.launch.py

Each domain operates independently.

WiFi Provisioning
==================

Initial Connection
-------------------

On first boot without WiFi credentials:

1. ESP32 creates SoftAP ``ESP32-Setup``
2. Connect to this network from your computer
3. Visit ``http://192.168.4.1/``
4. Enter your WiFi SSID and password
5. Device reboots and connects to your network

Reconnection
-----------  

After provisioning, ESP32 automatically:
- Connects to saved WiFi on boot
- Falls back to SoftAP if connection fails
- Maintains credentials in NVS flash

Manual Reset (if needed):
::

    # Hold GPIO9 button during boot to erase credentials

Debugging Communication
=======================

Monitor Topics
--------------

List all active topics:

::

    ros2 topic list

View topic content:

::

    ros2 topic echo /imu/data

Check message rate:

::

    ros2 topic hz /imu/data

Check Agent Connectivity
------------------------

Verify agent is running and firmware is connected:

::

    # In agent terminal, you should see:
    # "New client connected from IP:PORT with session id: X"

Run agent in verbose mode:

::

    ros2 run micro_ros_agent micro_ros_agent udp4 --port 8888 -v

Service Debugging
-----------------

List available services:

::

    ros2 service list

Call a service:

::

    ros2 service call /some_service std_srvs/srv/Empty

Performance Considerations
==========================

Bandwidth
---------

- **IMU (50 Hz, ~30 bytes)**: ~12 KB/s
- **Range Sensor (20 Hz, ~12 bytes)**: ~3 KB/s  
- **Total low bandwidth**: <100 KB/s

For high-frequency image streaming, use image_transport plugin.

Latency
-------

- **Network**: 5-20 ms (WiFi)
- **DDS Middleware**: 1-5 ms
- **Firmware processing**: <5 ms
- **Total**: ~10-30 ms typical

Reliability
-----------

UDP Transport:
  - Fast but lossy
  - Best for: Sensor streams
  - Graceful degradation with loss

TCP Transport:
  - Reliable but slower
  - Best for: Commands, configuration
  - Can block on packet loss

Related Documentation
======================

- :doc:`../firmware/esp32_controller` - Firmware communication details
- :doc:`system_contract` - Message specifications
- :doc:`../deployment/wifi_provisioning` - WiFi setup
- :doc:`../variants/gas_robot/subsystems/communication` - Gas Robot communication
