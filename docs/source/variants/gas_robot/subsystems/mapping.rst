========
Mapping
========

Gas heat-map mapping for leak detection.

Overview
========

This is not classic SLAM. The mapping package builds a **gas intensity field**
over time so the robot can identify hot spots, risk zones, and repeated leak
patterns.

Responsibilities
================

- accumulate filtered gas readings into a grid
- decay old readings over time
- keep track of spatial hot spots
- publish a risk map for navigation and alerts

Mapping Model
=============

::

    pose + filtered gas
            ->
    cell lookup
            ->
    intensity update
            ->
    decay / smoothing
            ->
    heat map + risk map

Map Types
=========

Heat Map
--------

Each cell stores gas intensity, not occupancy.

- value rises when gas concentration is high
- value slowly decays when readings drop
- useful for leak localization

Risk Map
--------

Derived from the heat map to support patrol decisions.

- marks high-risk areas
- can trigger slower motion or alert states
- can bias patrol routes toward suspicious regions

Configuration
=============

Configuration lives in ``gas_robot_ws/src/mapping/config/``.

Useful parameters:

- ``cell_size`` - map resolution
- ``decay_rate`` - how fast old gas values fade
- ``update_rate`` - how often the grid is updated
- ``risk_threshold`` - value that marks a hot zone

Output Topics
=============

.. list-table::
   :header-rows: 1
   :widths: 25 45

   * - Topic
     - Description
   * - ``/gas_heatmap``
     - Spatial gas intensity grid
   * - ``/risk_map``
     - Derived map for patrol and alert logic

Integration
===========

Mapping consumes:

- filtered gas from :doc:`perception`
- pose estimates from :doc:`state_estimation`

Mapping feeds:

- :doc:`navigation` for patrol decisions
- :doc:`communication` for alerts

Related Documentation
======================

- :doc:`perception` - Filtered gas input
- :doc:`state_estimation` - Pose tracking input
- :doc:`navigation` - Patrol logic uses the map
- :doc:`communication` - Alert output
