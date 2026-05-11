===============
Localization
===============

Position estimation and mapping utilities for Wall-E.

Overview
========

The localization subsystem estimates Wall-E's position and orientation within an environment using odometry, sensor fusion, and optional mapping.

Key Responsibilities
======================

- **Odometry Calculation**: Compute position from motor encoders
- **Sensor Fusion**: Combine data from IMU and odometry for accurate state
- **Pose Estimation**: Publish current pose and velocity
- **TF Broadcasting**: Maintain coordinate frame transformations
- **Map Integration**: Optional SLAM for environmental mapping

Localization Methods
====================

Odometry-Based Localization
-----------------------------

Uses motor encoder data to estimate relative motion:

- Two-wheel differential drive kinematics
- Frame transformations between ``base_link`` and ``odom``
- Periodic correction from sensor fusion

Sensor Fusion
--------------

Combines multiple sensor streams:

- **Encoders**: Short-term motion accuracy
- **IMU**: Gyroscope for heading estimation
- **Range Sensor**: Obstacle and landmark detection

Coordinate Frames
==================

.. list-table::
   :header-rows: 1
   :widths: 20 50

   * - Frame
     - Description
   * - ``world``
     - Global reference frame
   * - ``odom``
     - Odometry origin (local coordinate system)
   * - ``base_link``
     - Robot center (base footprint)
   * - ``imu_link``
     - IMU sensor frame

Published Topics
=================

.. list-table::
   :header-rows: 1
   :widths: 25 50

   * - Topic
     - Data Type
   * - ``/odom``
     - ``nav_msgs/Odometry``
   * - ``/tf``
     - ``tf2_msgs/TFMessage``
   * - ``/amcl_pose``
     - ``geometry_msgs/PoseWithCovarianceStamped``

Configuration
==============

Localization parameters and SLAM configuration are in ``wall_e_ws/src/localization/config/``.

Advanced Topics
================

Optional SLAM (Simultaneous Localization and Mapping) can be enabled for full environmental mapping.
See the ROS 2 Navigation documentation for setup instructions.

Related Documentation
======================

- :doc:`control` - Motion control and planning
- :doc:`feedback` - Sensor data for localization
- :doc:`../index` - Wall-E variant overview
- :doc:`../../hardware/communication_model` - Communication with firmware
- :doc:`../../references/references` - SLAM research papers and references
