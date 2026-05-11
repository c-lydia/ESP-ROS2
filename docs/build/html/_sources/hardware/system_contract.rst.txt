.. _system_contract:

================
System Contract
================

Overview
========

The system contract defines the formal interface and message specifications between system components. It ensures all modules communicate consistently and reliably.

Core Contract Principles
========================

1. **Message Semantics**: Each message has a well-defined type and purpose
2. **Data Flow**: Clearly defined publisher/subscriber relationships
3. **Reliability**: QoS policies ensure critical data delivery
4. **Versioning**: Backward compatibility maintained between versions
5. **Extensibility**: New messages can be added without breaking existing code

Firmware-to-Host Contract
==========================

Published Topics (Firmware → Host)
----------------------------------

**Sensor Data Topics**

.. list-table::
   :header-rows: 1
   :widths: 25 35 15

   * - Topic
     - Message Type
     - Rate
   * - ``/imu/data``
     - ``sensor_msgs/Imu``
     - 50 Hz
   * - ``/range/front``
     - ``sensor_msgs/Range``
     - 20 Hz
   * - ``/firmware/status``
     - Custom status message
     - 10 Hz
   * - ``/odom``
     - ``nav_msgs/Odometry``
     - 50 Hz

**Message Specifications**

``/imu/data`` (sensor_msgs/Imu)
  - Header: Timestamp, frame_id = "imu_link"
  - Linear acceleration (m/s²)
  - Angular velocity (rad/s)
  - Orientation (quaternion)
  - Covariance matrices for uncertainty

``/range/front`` (sensor_msgs/Range)
  - Header: Timestamp
  - Radiation type: ULTRASOUND
  - Field of view: ~15 degrees
  - Min/max range: 0.02-4.0 meters
  - Range reading: Distance in meters

Subscribed Topics (Host → Firmware)
------------------------------------

**Command Topics**

.. list-table::
   :header-rows: 1
   :widths: 25 40

   * - Topic
     - Message Type
   * - ``/cmd_vel``
     - ``geometry_msgs/Twist``
   * - ``/emergency_stop``
     - ``std_msgs/Bool``

**Message Specifications**

``/cmd_vel`` (geometry_msgs/Twist)
  - linear.x: Forward velocity (m/s), range [-1.0, 1.0]
  - angular.z: Rotation velocity (rad/s), range [-2π, 2π]
  - Other fields: Ignored

``/emergency_stop`` (std_msgs/Bool)
  - data: true = stop immediately, false = resume
  - Triggers motor safety cutoff

Host-to-Host ROS 2 Contract
============================

Standard Navigation Topics
---------------------------

.. list-table::
   :header-rows: 1
   :widths: 25 50

   * - Topic
     - Message Type
   * - ``/move_base/goal``
     - ``geometry_msgs/PoseStamped``
   * - ``/move_base/feedback``
     - ``move_base_msgs/MoveBaseFeedback``
   * - ``/tf``
     - ``tf2_msgs/TFMessage``

Coordinate Frames
=================

Standard TF Tree
----------------

::

    map
      └── odom
            └── base_link
                  ├── imu_link
                  ├── wheel_left
                  ├── wheel_right
                  └── range_link

Frame Descriptions
-------------------

**map**: Global fixed frame (origin at first known position)

**odom**: Odometry frame (resets on power-on, drifts over time)

**base_link**: Robot center, origin at wheel midpoint

**imu_link**: IMU sensor frame

**wheel_left/wheel_right**: Individual wheel frames

**range_link**: Range sensor frame

Transform Rates
---------------

- base_link → odom: 50 Hz (from odometry)
- base_link → imu_link: Static transform
- base_link → range_link: Static transform
- odom → map: 10 Hz (from localization)

Service Contracts
=================

Configuration Services
-----------------------

Services for runtime parameter changes:

**Service: /set_robot_config**

Request:
  - config_name: string
  - value: variant (int/float/string/bool)

Response:
  - success: bool
  - message: string

**Service: /get_robot_status**

Request: (empty)

Response:
  - battery_voltage: float
  - cpu_temp: float
  - motor_status: array of bool
  - wifi_signal: int

Action Contracts
================

Navigation Actions
------------------

**Action: /move_base/move**

Goal:
  - target_pose: geometry_msgs/PoseStamped
  - timeout: duration

Feedback:
  - current_pose: geometry_msgs/PoseStamped
  - distance_remaining: float

Result:
  - success: bool
  - final_pose: geometry_msgs/PoseStamped

Gas Robot Extension
===================

Additional Topics
------------------

.. list-table::
   :header-rows: 1
   :widths: 25 40

   * - Topic
     - Message Type
   * - ``/perception/objects``
     - Custom object list
   * - ``/slam/map``
     - ``nav_msgs/OccupancyGrid``
   * - ``/gas_sensor/reading``
     - Custom gas sensor msg

**Message: /gas_sensor/reading** (Custom)
  - Header: Timestamp
  - gas_concentration: float (ppm or %)
  - sensor_id: uint8
  - quality: uint8 (confidence 0-100)

Subsystem Contracts
====================

Wall-E Control Subsystem
------------------------

Inputs:
  - /cmd_vel (geometry_msgs/Twist)

Outputs:
  - /motor/feedback (motor speed feedback)
  - /motor/status (safety status)

Behavior:
  - Implements differential drive kinematics
  - Applies deadband to small velocities
  - Limits acceleration for smooth motion
  - Timeout: stops motors if no command for 500ms

Wall-E Feedback Subsystem
--------------------------

Inputs: (None - pure sensor data)

Outputs:
  - /imu/data
  - /range/front
  - /odom

Behavior:
  - IMU: Raw + filtered orientation
  - Range: Distance updates
  - Odometry: Integrated from wheel encoders

Wall-E Localization Subsystem
-----------------------------

Inputs:
  - /imu/data
  - /odom
  - /range/front

Outputs:
  - /tf (base_link → odom)
  - /pose (estimated position)
  - /pose_covariance (uncertainty estimate)

Behavior:
  - Fuses multiple sensor streams
  - Maintains uncertainty estimate
  - Corrects odometry drift

Version Management
==================

Message Versioning
-------------------

Use custom interface package for versioning:

::

    custom_interfaces/msg/v1/
      ├── SensorData.msg
      └── Command.msg
    
    custom_interfaces/msg/v2/
      ├── SensorData.msg  # Extended format
      └── Command.msg     # New fields

Compatibility Policy
--------------------

- **Major version change**: Breaking changes allowed
- **Minor version change**: Backward-compatible additions only
- **Patch version change**: Bug fixes, no API changes

Deprecation
-----------

Old message types remain available for 2 minor versions:

1. Add new improved message type
2. Deprecate old type (mark in docs)
3. Support both for 2 versions
4. Remove old type in next major release

Error Handling
==============

Communication Failures
-----------------------

- **Firmware disconnect**: Nodes should handle missing firmware gracefully
- **Network latency**: Use timeouts on critical commands
- **Message corruption**: Rely on DDS/UDP checksums

Recovery Strategies
-------------------

1. **Automatic reconnection**: micro-ROS agent auto-reconnects firmware
2. **State replication**: Important state republished periodically
3. **Heartbeat monitoring**: Detect stale connections
4. **Graceful degradation**: Continue with available data

Monitoring and Diagnostics
===========================

Diagnostic Topics
------------------

Monitor system health via ``/diagnostics``:

- Firmware connectivity
- Message latency
- Network bandwidth usage
- Battery status
- Temperature sensors

Logging
-------

Enable debug logging for troubleshooting:

::

    ros2 run <node> <executable> --ros-args --log-level DEBUG

Contract Compliance Testing
============================

Automated Checks
-----------------

Verify contract compliance:

::

    colcon test --packages-select <package>

Manual Verification
-------------------

::

    # Check message types
    ros2 topic info /imu/data
    
    # Verify message content
    ros2 topic echo /imu/data
    
    # Check rates
    ros2 topic hz /imu/data

Related Documentation
======================

- :doc:`communication_model` - Communication architecture
- :doc:`../firmware/esp32_controller` - Firmware implementation
- :doc:`../variants/wall_e/subsystems/index` - Wall-E subsystems
- :doc:`../variants/gas_robot/subsystems/index` - Gas Robot subsystems
