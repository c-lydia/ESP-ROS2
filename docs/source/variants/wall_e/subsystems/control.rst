=================
Control System
=================

Motion planning and actuator control for Wall-E's movement.

Overview
========

The control subsystem manages all motor actuation and motion planning for Wall-E. It coordinates with the firmware to execute movement commands received from ROS 2 nodes.

Key Responsibilities
======================

- **Motor Control**: PWM-based speed and direction control
- **Motion Planning**: Path planning and trajectory generation
- **State Management**: Current robot state tracking and feedback
- **Command Processing**: Handling velocity and position commands from higher-level planners

Architecture
============

The control system interfaces with:

- **Firmware (ESP32)**: Low-level PWM and GPIO control
- **Feedback System**: Odometry and encoder data
- **Navigation Stack**: Higher-level motion commands
- **Communication Layer**: ROS 2 message passing

Key Topics
===========

.. list-table::
   :header-rows: 1
   :widths: 30 35

   * - Topic
     - Description
   * - ``/cmd_vel``
     - Velocity commands
   * - ``/motor/left_speed``
     - Left motor speed feedback
   * - ``/motor/right_speed``
     - Right motor speed feedback

For detailed API documentation, see the package README and source code in ``wall_e_ws/src/control/``.

Related Documentation
======================

- :doc:`feedback` - Sensor feedback integration
- :doc:`localization` - Position estimation
- :doc:`../index` - Wall-E variant overview
- :doc:`../../hardware/communication_model` - Communication protocols
- :doc:`../../firmware/esp32_controller` - Firmware details
