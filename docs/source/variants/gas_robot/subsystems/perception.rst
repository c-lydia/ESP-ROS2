===========
Perception
===========

Gas signal filtering and sensor noise reduction.

Overview
========

Perception is narrow by design. It does not do object detection, SLAM, or
general scene understanding. Its job is to clean raw gas readings so mapping
can work with stable input.

Responsibilities
================

- smooth noisy gas readings
- reject spikes and obvious outliers
- maintain a calibrated baseline
- optionally merge repeated samples from the same sensor

Pipeline
========

::

    Raw Gas Readings
          ->
    Baseline Correction
          ->
    Noise Filtering
          ->
    Outlier Rejection
          ->
    Clean Gas Stream

Output Topics
==============

.. list-table::
   :header-rows: 1
   :widths: 30 45

   * - Topic
     - Description
   * - ``/perception/gas_filtered``
     - Cleaned gas concentration stream
   * - ``/perception/sensor_state``
     - Sensor health and calibration state

Configuration
==============

Parameters live in ``gas_robot_ws/src/perception/config/`` and should stay
simple: window size, baseline, and threshold values.

Calibration
===========

Before running patrols, calibrate the gas sensor against clean air:

1. sample baseline air
2. store the average offset
3. verify that the filtered signal settles near zero in clean air

Related Documentation
======================

- :doc:`hardware_interfaces` - Raw sensor sources
- :doc:`mapping` - Heat-map builder consumes filtered gas data
- :doc:`index` - Gas Robot subsystem overview
