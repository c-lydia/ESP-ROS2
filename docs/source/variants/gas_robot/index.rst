==================
Gas Robot Variant
==================

Gas Robot is an advanced variant of the platform, featuring expanded capabilities for autonomous navigation, environmental perception, computer vision, and gas detection.

.. toctree::
  :maxdepth: 2
  :caption: Gas Robot Specific

  setup
  subsystems/index

Getting Started with Gas Robot
================================

See the :doc:`../../getting_started/index` for initial setup, then proceed with :doc:`setup` for Gas Robot-specific configuration.

Core Subsystems
================

Gas Robot includes advanced subsystems:

- :doc:`subsystems/communication` - Multi-layer communication architecture
- :doc:`subsystems/hardware_interfaces` - Sensor and actuator drivers
- :doc:`subsystems/perception` - Environmental sensor fusion
- :doc:`subsystems/state_estimation` - Accurate pose tracking
- :doc:`subsystems/navigation` - Autonomous path planning and navigation
- :doc:`subsystems/mapping` - SLAM and environmental mapping
- :doc:`subsystems/cv_pipeline` - Computer vision processing

Shared Platform & Firmware
============================

Gas Robot shares the core platform with Wall-E:

- :doc:`../../hardware/architecture`
- :doc:`../../hardware/communication_model`
- :doc:`../../firmware/esp32_controller`

Development & Deployment
==========================

For development workflows, see :doc:`../../development/workflow_and_commands`.

For deployment information, see :doc:`../../deployment/wifi_provisioning`.

Related Documentation
======================

- :doc:`../../variants/wall_e/index` - Wall-E variant documentation
- :doc:`../../getting_started/index` - Getting started guide
- :doc:`../../hardware/architecture` - System architecture
- :doc:`../../firmware/esp32_controller` - Firmware documentation
- :doc:`../../software/ros2_stacks/index` - ROS 2 software stacks
- :doc:`../../references/index` - References and resources
