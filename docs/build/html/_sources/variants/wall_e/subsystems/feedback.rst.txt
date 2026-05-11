=================
Feedback System
=================

Sensor data processing and state feedback for Wall-E.

Overview
========

The feedback system aggregates sensor data from embedded hardware and publishes processed information to ROS 2 topics. It provides real-time state information needed for control and localization.

Key Responsibilities
======================

- **Sensor Polling**: Read data from IMU, range sensors, and encoders
- **Data Processing**: Filter and normalize raw sensor values
- **State Publishing**: Publish processed data to ROS 2 topics
- **Diagnostics**: Monitor sensor health and communication status

Hardware Integration
====================

Connected Sensors
------------------

- **IMU (MPU6050)**: 6-axis accelerometer/gyroscope over I2C
- **Range Sensor (HC-SR04)**: Ultrasonic distance measurement via GPIO
- **Encoders**: Motor speed feedback from firmware

Data Flow
---------

::

    Firmware (ESP32) 
        ↓ (micro-ROS)
    Feedback Node 
        ↓ (ROS 2)
    Sensor Topics

Published Topics
=================

.. list-table::
   :header-rows: 1
   :widths: 25 50

   * - Topic
     - Data Type
   * - ``/imu/data``
     - ``sensor_msgs/Imu``
   * - ``/range/front``
     - ``sensor_msgs/Range``
   * - ``/odom``
     - ``nav_msgs/Odometry``

Configuration
==============

Sensor configuration parameters are in ``wall_e_ws/src/feedback/config/``.

See the :doc:`../../hardware/communication_model` for details on micro-ROS communication.

Related Documentation
======================

- :doc:`control` - Motor control and actuation
- :doc:`localization` - Localization and state estimation
- :doc:`../index` - Wall-E variant overview
- :doc:`../../firmware/esp32_controller` - Firmware sensor integration
