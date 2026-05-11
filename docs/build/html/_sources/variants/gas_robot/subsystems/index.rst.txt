=======================
Gas Robot Subsystems
=======================

Gas Robot is a **gas-leak mapping robot**, not a full autonomy stack.
The docs below follow the architecture you described: raw sensing, state estimation,
gas filtering, heat-map mapping, simple patrol navigation, and alerts.

System Flow
===========

::

    hardware_interfaces
      ->
    state_estimation
      ->
    perception
      ->
    mapping
      ->
    navigation
      ->
    communication

.. toctree::
   :maxdepth: 1

   hardware_interfaces
   state_estimation
   perception
   mapping
   navigation
   communication
   cv_pipeline

Module Roles
============

.. list-table::
    :header-rows: 1
    :widths: 22 55

    * - Module
       - Role
    * - **hardware_interfaces**
       - Raw gas, IMU, range, and actuator drivers
    * - **state_estimation**
       - Odometry, pose tracking, and TF output
    * - **perception**
       - Filter gas readings and smooth noise
    * - **mapping**
       - Build gas heat maps and risk maps
    * - **navigation**
       - Mission planning and waypoint patrol
    * - **communication**
       - Alerts, dashboard updates, and status output
    * - **cv_pipeline**
       - Optional camera/vision experiments

Design Intent
=============

This architecture is intentionally narrow:

- keep the gas sensor path easy to debug
- separate pose estimation from sensor filtering
- treat mapping as a gas-intensity field, not classic SLAM
- keep navigation simple and mission-driven
- use communication for alerts and operator feedback

Related Documentation
======================

- :doc:`../setup` - Workspace setup and configuration
- :doc:`../../../hardware/system_contract` - Message interfaces
- :doc:`../../../hardware/communication_model` - Data flow model
