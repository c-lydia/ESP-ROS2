.. _concepts:

========
Concepts
========

This page describes the core system concepts used in Wall-E and how data flows through firmware, feedback, localization, and control.

Layered Roles
=============

The stack is organized into four responsibilities:

- **firmware**: hardware I/O, real-time safety, and actuator output on ESP32
- **feedback**: filtering and fusion of raw sensor streams
- **localization**: state estimation from fused signals
- **control**: converting operator/autonomy intent into actuator commands

Architecture Flow (Text Diagram)
================================

.. code-block:: text

   ROS 2
   ├─ control
   │  ├─ Gamepad
   │  └─ robot_control
   ├─ feedback
   │  ├─ imu_filter
   │  ├─ ultrasonic_filter
   │  └─ sensor_fusion
   └─ localization
      ├─ inverse_kinematic
      └─ odometry

   firmware
   └─ esp32_controller

Main flow:

1. ``esp32_controller`` publishes raw ``/imu/data`` and ``/range/data``.
2. ``imu_filter`` and ``ultrasonic_filter`` clean those signals.
3. ``sensor_fusion`` combines filtered streams for stable state signals.
4. ``odometry`` publishes platform state on ``/odom``.
5. ``robot_control`` consumes gamepad + filtered sensors + odometry and publishes ``/cmd_vel``.
6. ``robot_control`` also maps a selected gamepad axis to ``/servo_cmd`` (degrees).
7. ``inverse_kinematic`` converts ``/cmd_vel`` to ``/motor_cmd``.

Control Loop Topology
=====================

``robot_control`` uses a cascaded design:

- outer loop: P/PD on range/heading position error to generate speed setpoints
- inner loop: PI on speed error to generate ``/cmd_vel`` outputs
- speed setpoints are saturated and rate-limited before PI tracking
- servo path: axis value in ``[-1, 1]`` maps to ``[servo_min_angle_deg, servo_max_angle_deg]``

This keeps PI where it is most stable in this architecture: speed control.

Gamepad Input Mapping
=====================

Default operator mapping in ``robot_control``:

- enable gate: ``LB`` (parameter ``enable_button=lb``)
- hold/PI button: ``A`` (parameter ``pi_mode_button=a``)
- manual linear command: ``-left_stick_y``
- manual angular command: ``left_stick_x``
- servo command: ``servo_axis`` (default ``right_stick_y``) mapped to angle range

Servo mapping details:

- axis value is clamped to ``[-1, 1]``
- optional inversion when ``servo_axis_invert=true``
- mapped into ``[servo_min_angle_deg, servo_max_angle_deg]``
- if ``servo_only_when_enabled=true`` and enable is not held, command falls back to ``servo_default_angle_deg``

By default, triggers and D-pad are available on ``/gamepad`` but are not consumed by motion logic.

Raw vs Filtered Signals
=======================

Raw sensors are noisy and may contain spikes or short dropouts.
The host feedback stage improves signal quality before localization or control:

- IMU path: bias-aware fusion in ``imu_filter.py``
- Range path: validity checks + median + EMA in ``ultrasonic_filter.py``

Fusion Strategy
===============

The current fusion approach prioritizes practical deployment over model-heavy complexity:

- prediction from IMU-derived motion trend
- correction from filtered range observations

This gives robust behavior with straightforward parameter tuning.

For this ground robot, fusion outputs are practical local state signals for control, not global altitude estimates.

Odometry Model
==============

Current odometry combines command inputs and available sensors:

- translational integration from ``/cmd_vel``
- heading from IMU yaw when available
- fallback heading integration if IMU yaw is unavailable

This is intentionally lightweight and suitable for short-horizon control.

Safety Model
============

Safety remains firmware-local and independent from host nodes:

- watchdog supervision
- motor command timeout
- emergency stop topic handling
- WiFi provisioning + reconnect behavior

If host nodes are restarted, firmware safety constraints still apply.

Tuning Guidance
===============

Tune each layer separately for faster iteration:

- firmware layer: motor/servo limits, GPIO mapping, timing
- feedback layer: filter alpha, window size, jump gate, fusion gains
- localization/control layer: kinematic assumptions and controller gains

Related Reading
===============

- :doc:`architecture`
- :doc:`firmware/esp32_controller`
- :doc:`workflow_and_commands`
