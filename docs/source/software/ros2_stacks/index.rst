====================
ROS 2 Software Stacks
====================

Core ROS 2 packages and middleware infrastructure.

.. toctree::
  :maxdepth: 1

Overview
========

The ROS 2 software stacks provide the foundational packages and middleware that support both Wall-E and Gas Robot variants.

Shared Stacks
=============

These ROS 2 packages are used across all robot variants:

Custom Interfaces
------------------

Defines shared message types and service interfaces:

- Robot configuration messages
- Sensor data types
- Command interfaces
- Custom Gas Robot messages (for Gas Robot variant)

Located in: ``*/src/custom_interfaces/``

Common Utilities
----------------

Shared utility packages:

- Communication helpers
- Logging and diagnostics
- Common algorithms
- Testing utilities

Middleware & Communication
==========================

DDS Middleware
--------------

ROS 2 uses Data Distribution Service (DDS) for publish/subscribe:

- Quality of Service (QoS) policies
- Multi-domain networking
- Security and encryption support

micro-ROS Integration
---------------------

Connects firmware to ROS 2:

- Agent bridge for ESP32 communication
- Reliable UDP messaging
- Message serialization and deserialization

See :doc:`../../hardware/communication_model` for details.

Building ROS 2 Packages
=======================

Build all packages:

::

    cd micro_ros_ws
    colcon build

Build specific package:

::

    colcon build --packages-select custom_interfaces

Build with tests:

::

    colcon build --packages-select <package> --cmake-args -DCMAKE_BUILD_TYPE=Debug

Testing
=======

Run unit tests:

::

    colcon test --packages-select custom_interfaces

View test results:

::

    colcon test-result --verbose

Debugging
=========

Enable verbose output:

::

    colcon build --packages-select <package> --event-handlers console_direct+

Run with debugging:

::

    ros2 run --prefix 'gdb -ex run --args' <package> <executable>

See :doc:`../../development/workflow_and_commands` for advanced debugging techniques.
