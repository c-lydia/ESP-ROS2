.. _getting_started:

===============
Getting Started
===============

Welcome! This guide will help you set up the robotics workspace for either the Wall-E or Gas Robot variant.

System Requirements
===================

Minimum Requirements
--------------------

- **Operating System**: Ubuntu 20.04 LTS (Linux host recommended)
- **Docker & Docker Compose**: Latest stable version
- **Git**: For cloning the repository
- **Memory**: 8GB RAM minimum (16GB recommended for Gas Robot)
- **Disk Space**: 20GB free space for build artifacts
- **Python**: Python 3.8+

Hardware Requirements
---------------------

- **ESP32 Development Board**: ESP32-S3 recommended
- **USB Cable**: For programming and debugging
- **Optional Sensors**:
  - IMU Sensor (MPU6050) - I2C
  - Ultrasonic Range Sensor (HC-SR04) - GPIO
  - Gas Sensors (for Gas Robot variant)
  - Camera Module (optional, for vision-based navigation)

Quick Start (5 minutes)
=======================

1. **Clone the Repository**

   ::

       git clone https://github.com/c-lydia/wall_e.git
       cd wall_e/micro_ros_ws

2. **Start Docker Services**

   ::

       docker compose up -d

   Verify services are running:

   ::

       docker compose ps

3. **Enter Workspace Container**

   ::

       docker compose exec workspace bash
       cd /micro_ros_ws

4. **Source ROS 2 and Build**

   ::

       source /opt/ros/humble/setup.bash
       colcon build
       source install/setup.bash

5. **Choose Your Robot Variant**

   For Wall-E:

   ::

       ros2 launch wall_e_description wall_e.launch.py

   For Gas Robot:

   ::

       colcon build --packages-select gas_robot_description
       ros2 launch gas_robot_description gas_robot.launch.py

Detailed Setup
==============

Environment Configuration
--------------------------

Set up your environment variables before working:

::

    # ROS 2 domain ID (for multi-robot networks, use different IDs)
    export ROS_DOMAIN_ID=1

    # Optional: set middleware to cyclonedds for better performance
    export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp

Building the Workspace
-----------------------

**Build all packages:**

::

    cd /micro_ros_ws
    colcon build

**Build specific packages:**

::

    colcon build --packages-select custom_interfaces wall_e_description

**Clean build (remove build artifacts):**

::

    colcon build --cmake-target clean

ESP32 Firmware Setup
====================

Prerequisites for Firmware
---------------------------

- ESP32 development board connected via USB
- ESP-IDF tools installed (or use Docker container)

Configure and Build Firmware
-----------------------------

1. **Configure for your robot and transport:**

   ::

       ros2 run micro_ros_setup configure_firmware.sh esp32_controller \
         -t udp \
         -i 192.168.1.2 \
         -p 8888

   Parameters:
   - ``-t udp``: Use UDP transport (change to ``tcp`` if needed)
   - ``-i``: IP address of ROS 2 host (docker container IP)
   - ``-p``: Port number for micro-ROS agent

2. **Build the firmware:**

   ::

       ros2 run micro_ros_setup build_firmware.sh

3. **Flash to ESP32:**

   ::

       ros2 run micro_ros_setup flash_firmware.sh

4. **Monitor serial output:**

   ::

       ros2 run micro_ros_setup monitor_serial.sh

WiFi Provisioning
------------------

On first boot with no stored WiFi credentials:

1. ESP32 creates SoftAP (access point) named ``ESP32-Setup``
2. Connect your device to this open network
3. Open ``http://192.168.4.1/`` in your browser
4. Enter your WiFi SSID and password
5. Device saves credentials and reboots
6. Automatically connects to your WiFi on next boot

See :doc:`../deployment/wifi_provisioning` for detailed instructions.

Docker Container Setup
======================

The Docker environment provides:

- **ROS 2 Humble** development environment
- **Python** with required packages
- **colcon** build system
- **micro-ROS** agent
- **Development tools** (git, nano, etc.)

**Start services:**

::

    docker compose up -d

**View logs:**

::

    docker compose logs -f workspace

**Stop services:**

::

    docker compose down

**Reset database (removes persistent data):**

::

    docker compose down -v

X11 Display Setup (GUI)
-----------------------

For visualization tools (RViz, Gazebo):

**On Linux host before launching GUI apps:**

::

    xhost +si:localuser:root

**Inside container, any GUI app will display on your desktop.**

Choosing Your Robot Variant
============================

Wall-E Variant
--------------

Original robot with manual control and sensor integration:

- Built-in motion control
- Sensor feedback (IMU, range, encoders)
- Manual teleoperation support
- Suitable for learning ROS 2 basics

**Start with**: :doc:`../variants/wall_e/index`

Gas Robot Variant
-----------------

Advanced robot with autonomous navigation:

- Full autonomous navigation stack
- Computer vision processing
- SLAM and mapping
- Environmental sensing
- Suitable for advanced robotics projects

**Start with**: :doc:`../variants/gas_robot/index`

Workspace Structure
===================

::

    micro_ros_ws/
    ├── src/
    │   ├── micro_ros_setup/        # Firmware build tools
    │   └── uros/                   # micro-ROS packages
    ├── wall_e_ws/
    │   └── src/                    # Wall-E packages
    ├── gas_robot_ws/
    │   └── src/                    # Gas Robot packages
    ├── firmware/
    │   ├── custom/                 # Custom firmware apps
    │   ├── freertos_apps/          # FreeRTOS reference apps
    │   └── esp32/                  # ESP-IDF configurations
    ├── docs/                       # Documentation (you are here)
    └── docker/                     # Docker configuration

Building Without Docker
========================

**If you prefer native development:**

1. Install ROS 2 Humble: https://docs.ros.org/en/humble/Installation.html
2. Install colcon: https://colcon.readthedocs.io/
3. Install micro-ROS dependencies
4. Build the workspace normally:

   ::

       source /opt/ros/humble/setup.bash
       colcon build

Common Issues & Solutions
=========================

**Docker container fails to start:**

::

    docker compose logs workspace

**ROS 2 nodes can't communicate:**

- Check ``ROS_DOMAIN_ID`` is consistent (default: 1)
- Verify network connectivity between components
- Ensure DDS middleware is compatible

**Firmware won't compile:**

- Verify ESP-IDF version matches firmware requirements
- Clean and rebuild: ``colcon build --cmake-target clean``
- Check serial port is properly connected

**GUI apps don't display:**

- Run ``xhost +si:localuser:root`` on host before launching
- Verify ``DISPLAY`` environment variable is set

See :doc:`../references/troubleshooting` for more solutions.

Next Steps
==========

1. **Choose your variant:**
   - :doc:`../variants/wall_e/index` for Wall-E
   - :doc:`../variants/gas_robot/index` for Gas Robot

2. **Read the architecture:**
   - :doc:`../hardware/architecture` - System overview
   - :doc:`../hardware/communication_model` - Communication layer

3. **Explore subsystems:**
   - :doc:`../variants/wall_e/subsystems/index` - Wall-E subsystems
   - :doc:`../variants/gas_robot/subsystems/index` - Gas Robot subsystems

4. **Development:**
   - :doc:`../development/workflow_and_commands` - Day-to-day commands
   - :doc:`../firmware/esp32_controller` - Firmware documentation

5. **Reference:**
   - :doc:`../references/index` - Concepts, papers, and resources
   - :doc:`../references/troubleshooting` - Common issues
