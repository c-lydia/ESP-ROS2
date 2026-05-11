.. _gas_robot_navigation:

===========
Navigation
===========

Mission planning and simple waypoint patrol for gas mapping.

Overview
========

This package is intentionally lightweight. It does not implement a full Nav2 stack.
Instead, it coordinates patrol behavior so the robot can sweep an area while
collecting gas readings.

Concept
=======

The navigation layer is split into two responsibilities:

Mission Planner
---------------

- choose patrol routes
- decide when to visit waypoints
- pause or re-route based on gas map results

Motion Planner
--------------

- convert waypoint targets into velocity commands
- keep motion slow and predictable for sensing
- stop or slow down when alerts are raised

Data Flow
=========

.. list-table::
   :header-rows: 1
   :widths: 25 50

   * - Input
     - Use
   * - ``/odom``
     - Current robot pose
   * - ``/gas_heatmap``
     - Bias patrol toward interesting areas
   * - ``/risk_map``
     - Avoid high-risk or unsafe regions

.. list-table::
   :header-rows: 1
   :widths: 25 50

   * - Output
     - Use
   * - ``/cmd_vel``
     - Velocity command to base controller
   * - ``/patrol/status``
     - Current waypoint and patrol state

Patrol Behavior
===============

Typical flow:

1. load waypoints from config
2. drive to a waypoint
3. pause briefly for gas sampling
4. publish patrol status
5. continue to the next waypoint

This keeps motion simple and stable for gas sensing.

Configuration
=============

Waypoints and timing belong in ``gas_robot_ws/src/navigation/config/``.

Recommended settings:

- low linear velocity
- low angular velocity
- short dwell time at each waypoint
- loop patrol for repeated area coverage

Related Documentation
======================

- :doc:`index` - Gas Robot subsystem overview
- :doc:`mapping` - Heat-map driven patrol decisions
- :doc:`state_estimation` - Pose tracking for patrol
- :doc:`communication` - Status and alerts
