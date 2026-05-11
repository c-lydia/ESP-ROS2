.. _gas_robot_cv_pipeline:

===========
CV Pipeline
===========

Optional camera and vision experiments for Gas Robot.

Overview
========

This package is not part of the core gas-leak workflow. It is a placeholder for
camera-based experiments if you decide to add them later.

Intended Use
============

- camera capture
- debug image publishing
- marker detection or simple visual checks
- experiment-only vision features

Not Core
========

The gas robot does not need object detection for its main mission.
Keep this package optional unless you have a specific camera use case.

Possible Topics
===============

.. list-table::
   :header-rows: 1
   :widths: 25 45

   * - Topic
     - Use
   * - ``/camera/image_raw``
     - Raw camera frames
   * - ``/camera/debug_image``
     - Annotated image output
   * - ``/vision/status``
     - Vision pipeline health

Related Documentation
======================

- :doc:`index` - Gas Robot subsystem overview
- :doc:`hardware_interfaces` - Raw hardware layer
- :doc:`communication` - Optional operator display integration============================
Computer Vision Pipeline
============================

Advanced image processing and vision-based capabilities for Gas Robot.

Overview
========

The CV pipeline processes visual data for obstacle detection, landmark identification, and visual navigation capabilities.

Processing Pipeline
===================

Raw Image
   ↓
Preprocessing (Distortion Correction, Color Space Conversion)
   ↓
Feature Detection (Corners, Edges, Blobs)
   ↓
Object Detection & Classification
   ↓
Spatial Reasoning (3D Reconstruction)
   ↓
Decision Making (Navigation/Grasping)

Key Processing Nodes
====================

Image Capture
--------------

- Camera driver and calibration
- Raw image publishing
- Frame rate control

Image Processing
----------------

- Color space conversion (RGB ↔ HSV, Grayscale)
- Histogram equalization
- Gaussian blur and edge detection
- Morphological operations

Feature Detection
------------------

- Corner detection (Harris, FAST, ORB)
- Edge detection (Canny, Sobel)
- Contour detection and analysis

Object Detection
-----------------

- Template matching
- Blob detection
- Deep learning inference (if GPU available)

Vision Topics
=============

.. list-table::
   :header-rows: 1
   :widths: 30 45

   * - Topic
     - Type
   * - ``/camera/image_raw``
     - ``sensor_msgs/Image``
   * - ``/camera/camera_info``
     - ``sensor_msgs/CameraInfo``
   * - ``/vision/objects``
     - Detected objects and landmarks
   * - ``/vision/debug_image``
     - Annotated image for visualization

Configuration
==============

Vision parameters are in ``gas_robot_ws/src/cv_pipeline/config/``:

- ``camera_calibration.yaml`` - Intrinsic camera parameters
- ``detectors.yaml`` - Feature and object detection settings
- ``processors.yaml`` - Image processing pipeline parameters

Camera Calibration
==================

Calibrate camera for distortion correction:

::

    ros2 run cv_pipeline calibrate_camera

Output:

- Intrinsic matrix (focal length, principal point)
- Distortion coefficients
- Rectification map

Using calibration:

::

    ros2 launch cv_pipeline cv_launch.py calibration:=camera_calibration.yaml

Performance Optimization
========================

For resource-constrained platforms:

- **Reduce resolution**: Smaller images = faster processing
- **Lower frequency**: Process every Nth frame
- **Simplified algorithms**: Use faster feature detectors
- **GPU acceleration**: Offload CUDA operations to GPU

Debugging Vision
================

Visualize processed results:

::

    ros2 run rqt_image_view rqt_image_view /vision/debug_image

Monitor performance:

::

    ros2 topic hz /vision/objects

Common Issues
=============

**Poor detection in low light**: Increase exposure or add lighting

**High latency**: Reduce image resolution or detection threshold

**Unstable tracking**: Apply temporal filtering to detections

See :doc:`../../references/troubleshooting` for more issues.

Related Documentation
======================

- :doc:`perception` - Sensor fusion with vision data
- :doc:`navigation` - Vision-based navigation
- :doc:`../index` - Gas Robot variant overview
- :doc:`../../references/references` - Computer vision and deep learning papers
