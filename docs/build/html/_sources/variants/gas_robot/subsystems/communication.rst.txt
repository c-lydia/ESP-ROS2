====================
Communication
====================

Alerts, dashboard updates, and operator-facing messaging for Gas Robot.

Overview
========

This package is not the whole ROS network. It is the application-facing layer
that turns mapping results and safety states into something operators can see
or react to.

Responsibilities
================

- publish leak alerts
- drive dashboard status updates
- expose buzzer/indicator events
- provide mission status to the operator

Data Flow
=========

::

    mapping / navigation / state_estimation
     ->
         communication layer
     ->
      dashboard / buzzer / notifications

Example Outputs
===============

.. list-table::
   :header-rows: 1
   :widths: 25 45

   * - Topic / Signal
     - Purpose
   * - ``/alerts/gas``
     - High gas concentration warning
   * - ``/alerts/risk_zone``
     - Robot entered a risky map region
   * - ``/dashboard/status``
     - Operator status summary
   * - ``/dashboard/heatmap``
     - Heat-map display stream

Notes
=====

This layer can later connect to Telegram, SMS, a web dashboard, or a local
buzzer without changing the rest of the robot stack.

Related Documentation
======================

- :doc:`mapping` - Heat map source
- :doc:`navigation` - Patrol decisions
- :doc:`../index` - Gas Robot subsystem overview
- :doc:`../../../hardware/communication_model` - Platform transport model

