====================
State Estimation
====================

Odometry and pose tracking for Gas Robot.

Overview
========

This package answers one question: **where is the robot now?**

It is separated from perception on purpose. Perception cleans gas data; state
estimation tracks motion and pose.

Responsibilities
================

- integrate wheel odometry
- fuse IMU heading information
- publish pose and TF transforms
- provide a stable base for mapping and navigation

State Model
===========

::

    wheel motion + IMU
      ->
    odometry integration
      ->
    pose estimate
      ->
    tf tree output

Output Topics
=============

.. list-table::
   :header-rows: 1
   :widths: 25 45

   * - Topic
     - Description
   * - ``/odometry/wheels``
     - Wheel-based odometry estimate
   * - ``/state/pose``
     - Estimated robot pose
   * - ``/state/velocity``
     - Linear and angular velocity estimate
   * - ``/tf``
     - Transform tree for other nodes

Configuration
=============

Parameters live in ``gas_robot_ws/src/state_estimation/config/``.

Common tuning values:

- wheel radius
- wheelbase
- IMU heading offset
- update rate

Related Documentation
======================

- :doc:`hardware_interfaces` - Raw sensor inputs
- :doc:`perception` - Clean gas input is separate
- :doc:`mapping` - Pose is consumed by the heat map
- :doc:`navigation` - Patrol uses pose estimates
