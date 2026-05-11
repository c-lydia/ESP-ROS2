==================
Gas Robot Setup
==================

Setup and configuration instructions specific to the Gas Robot variant.

Overview
========

Gas Robot extends the base platform with additional capabilities for gas detection, environmental mapping, autonomous navigation, and computer vision processing. This guide covers the specific setup required for the Gas Robot variant.

Prerequisites
==============

- Docker and Docker Compose installed
- ESP32 development board with current firmware
- Required Python dependencies (see :doc:`../../getting_started/index`)
- USB cable for ESP32 programming
- Gas sensors and hardware (detailed in :ref:`hardware-requirements`)

Installation
=============

1. **Clone and Navigate**

   Follow the general getting started guide at :doc:`../../getting_started/index`

2. **Build Gas Robot Workspace**

   ::

       cd gas_robot_ws
       colcon build

3. **Start Services**

   ::

       docker compose up -d

Hardware Requirements
======================

Gas Robot adds these hardware components to the base platform:

- **Gas Sensors**: Configured for detection and measurement
- **Navigation Sensors**: Enhanced range and vision capabilities
- **Communication Interfaces**: For gas sensor data aggregation

See :ref:`hardware-interfaces` for sensor specifications.

Core Subsystems
================

Gas Robot includes expanded subsystems for advanced robotics:

.. list-table::
   :header-rows: 1
   :widths: 25 50

   * - Subsystem
     - Purpose
   * - **Communication**
     - Inter-node and sensor communication layer
   * - **Control**
     - Motor and actuator control (shared with Wall-E)
   * - **Hardware Interfaces**
     - Low-level sensor and actuator drivers
   * - **Perception**
     - Computer vision and sensor fusion
   * - **State Estimation**
     - Pose and state tracking
   * - **Navigation**
     - Path planning and autonomous movement
   * - **Mapping**
     - Environmental mapping and SLAM
   * - **CV Pipeline**
     - Advanced computer vision processing

Configuration
==============

Configuration files are located in ``gas_robot_ws/src/*/config/`` for each subsystem.

Key Configuration Files
------------------------

- ``robot_interfaces/config/gas_robot.yaml`` - Robot configuration
- ``hardware_interfaces/config/sensors.yaml`` - Sensor parameters
- ``navigation/config/nav_params.yaml`` - Navigation settings
- ``perception/config/vision.yaml`` - Computer vision parameters

Environment Variables
=======================

Set the following environment variables for Gas Robot development:

::

    export GAS_ROBOT_WS=/path/to/gas_robot_ws
    export ROS_DOMAIN_ID=1  # If running multiple robots

Building and Testing
====================

Build Individual Packages
--------------------------

::

    colcon build --packages-select hardware_interfaces
    colcon build --packages-select perception

Run Tests
---------

::

    colcon test --packages-select <package_name>

Troubleshooting
===============

If you encounter issues during setup:

1. Verify Docker services are running: ``docker compose ps``
2. Check firmware version matches: :doc:`../../firmware/esp32_controller`
3. Review sensor connections against hardware specs
4. Consult :doc:`../../references/troubleshooting`

Next Steps
==========

After setup:

1. Review subsystem documentation in ``src/`` subdirectories
2. Start with perception or navigation tutorials
3. Consult the :doc:`../../development/workflow_and_commands` guide
