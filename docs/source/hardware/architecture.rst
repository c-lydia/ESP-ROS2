.. _architecture:

============
Architecture
============

System Overview
===============

This project is a modular robotics platform composed of four independent layers:

1. **Platform Layer** – Hardware, firmware, and communication bridge
2. **ROS 2 Stack Layer** – Robot-specific behavior systems
3. **Subsystem Layer** – Reusable perception, mapping, and estimation algorithms
4. **Development Layer** – Build, simulation, and tooling infrastructure

Each layer communicates through strictly defined ROS 2 interfaces.

---

High-Level System Diagram
=========================

.. code-block:: text

   +----------------------+
   |   ROS 2 Stacks       |
   |----------------------|
   | Wall-E (manual)      |
   | Gas Robot (autonomy) |
   +----------+-----------+
              |
              v
   +----------------------+
   |   Subsystems         |
   |----------------------|
   | perception           |
   | state_estimation     |
   | mapping              |
   | navigation           |
   +----------+-----------+
              |
              v
   +----------------------+
   |   Platform Layer     |
   |----------------------|
   | ROS 2 middleware     |
   | micro-ROS agent      |
   | message contracts    |
   +----------+-----------+
              |
              v
   +----------------------+
   |  ESP32 Firmware      |
   |----------------------|
   | FreeRTOS controller  |
   | sensors (IMU, range) |
   | motor interface      |
   +----------------------+

---

Platform Layer
==============

The platform layer defines the physical and communication boundary of the system.

ESP32 Firmware
--------------

- Runs FreeRTOS
- Hosts micro-ROS client
- Publishes raw sensor data:
  - IMU (MPU6050 or equivalent)
  - Range sensor (ultrasonic or LiDAR)
- Receives actuator commands:
  - motor velocity commands
  - servo commands (if available)

Host ROS 2 Middleware
---------------------

- micro-ROS agent bridges ESP32 to ROS 2
- Ensures reliable UDP communication
- Converts embedded data into ROS 2 message types

---

Subsystem Layer
================

Subsystems are reusable algorithmic modules independent of robot identity.

Perception
----------

- Camera processing pipeline
- Gas concentration filtering
- Feature extraction (e.g., ArUco, object detection)

State Estimation
----------------

- Sensor fusion (IMU + odometry + encoder if available)
- Pose estimation
- Velocity estimation

Mapping
-------

- Occupancy grid mapping
- Gas concentration heatmap generation

Navigation
----------

- Motion planning
- Mission planning
- Path execution interface

---

ROS 2 Stack Layer
==================

This layer defines robot-specific behavior.

Each robot stack is a **composition of subsystems**, not new algorithms.

Example stacks:

- Wall-E Stack → manual teleoperation system
- Gas Robot Stack → autonomous exploration system

Each stack defines:
- node composition
- control policy
- behavior logic
- mission structure

IMPORTANT:
Subsystems must remain robot-agnostic.

---

Data Flow Architecture
======================

Sensor Flow:

1. ESP32 publishes raw sensor data
2. Optional hardware-level filtering (lightweight only)
3. Subsystems perform full filtering + fusion
4. State estimation produces `/odom` and pose estimates

Control Flow:

1. ROS 2 Stack generates intent (`cmd_vel`, mission goals)
2. Navigation converts intent → motion commands
3. Platform layer forwards commands to firmware
4. ESP32 executes motor control

---

Communication Model
===================

All inter-layer communication uses ROS 2 topics and messages:

- ``sensor_msgs/msg/Imu``
- ``sensor_msgs/msg/Range``
- ``geometry_msgs/msg/Twist``
- ``nav_msgs/msg/Odometry``

Custom messages are allowed only in:
``robot_interfaces`` package.

---

Design Principles
==================

- Hardware is isolated in firmware layer
- Algorithms are isolated in subsystem layer
- Robot behavior is isolated in ROS 2 stack layer
- No cross-layer logic leakage allowed

---

Extensibility
=============

This architecture supports:

- Multiple robots (Wall-E, Gas Robot, future systems)
- Swappable subsystems (e.g., different SLAM methods)
- Hardware abstraction (ESP32 or alternative controllers)
- Simulation and real hardware parity

---

References
==========

All theoretical and implementation references are listed in :doc:`references`.