======================
Workflow and Commands
======================

This page documents the complete development workflow and common commands for both Wall-E and Gas Robot variants.

Development Workflow Overview
=============================

Standard Development Cycle
---------------------------

1. **Start Development Environment**
   - Launch Docker containers
   - Enter workspace container
   - Source ROS 2 environment

2. **Develop/Modify Code**
   - Edit source files in your host editor (automatically synced via Docker volume)
   - Create new ROS 2 packages or modify existing subsystems

3. **Build Packages**
   - Build incrementally or rebuild all
   - Watch for compilation errors

4. **Test and Validate**
   - Run individual nodes
   - Monitor topics and services
   - Use RViz for visualization

5. **Debug Issues**
   - Check logs and diagnostics
   - Monitor hardware (firmware) via serial
   - Trace communication via ROS 2 tools

6. **Iterate**
   - Make changes and rebuild
   - Test modified components

Docker Environment
==================

Starting Services
-----------------

Start all services in background:

::

    docker compose up -d

Start with output to console (useful for debugging):

::

    docker compose up

Rebuild images (if Dockerfile changed):

::

    docker compose up --build -d

Stopping Services
------------------

Stop all services (containers persist):

::

    docker compose stop

Stop and remove all containers:

::

    docker compose down

Stop and remove all data (WARNING: deletes volumes):

::

    docker compose down -v

Viewing Service Status
----------------------

List running services:

::

    docker compose ps

View service logs:

::

    docker compose logs -f workspace

View logs for specific service:

::

    docker compose logs -f workspace

Workspace Container Access
===========================

Enter the workspace container:

::

    docker compose exec workspace bash

Execute a single command inside container:

::

    docker compose exec workspace colcon build

Exit container:

::

    exit

Multi-window Development
------------------------

Open multiple terminals to the workspace:

::

    # Terminal 1: Enter workspace
    docker compose exec workspace bash
    
    # Terminal 2: Monitor logs
    docker compose logs -f workspace
    
    # Terminal 3: Run ROS tools
    docker compose exec workspace ros2 topic list

ROS 2 Environment Setup
========================

Inside the container, set up your ROS 2 environment:

::

    # Source the ROS 2 installation
    source /opt/ros/humble/setup.bash
    
    # Source the workspace overlay
    source /micro_ros_ws/install/setup.bash
    
    # Set domain ID for robot identification
    export ROS_DOMAIN_ID=1

These commands are typically added to your shell profile for convenience.

Building Packages
=================

Build All Packages
-------------------

Full rebuild of entire workspace:

::

    cd /micro_ros_ws
    colcon build

Build with verbose output:

::

    colcon build --verbose

Build specific packages:

::

    colcon build --packages-select custom_interfaces wall_e_description

Build single package with dependencies:

::

    colcon build --packages-up-to control

Parallel builds (faster on multi-core):

::

    colcon build --parallel-workers 4

Clean Build
-----------

Clean intermediate build files:

::

    colcon build --cmake-target clean

Remove all build artifacts:

::

    rm -rf build/ install/ log/
    colcon build

Build with sanitizers (detect memory issues):

::

    colcon build --cmake-args -DCMAKE_CXX_FLAGS="-fsanitize=address"

Launching Nodes and Systems
============================

Wall-E Launch
--------------

Integrated launch with visualization:

::

    ros2 launch wall_e_description wall_e.launch.py

RViz only (no simulation):

::

    ros2 launch wall_e_description wall_e.launch.py use_gazebo:=false use_rviz:=true

With joint state publisher:

::

    ros2 launch wall_e_description wall_e.launch.py use_joint_state_publisher:=true

Gas Robot Launch
-----------------

Start Gas Robot with all subsystems:

::

    ros2 launch gas_robot_description gas_robot.launch.py

With specific parameters:

::

    ros2 launch gas_robot_description gas_robot.launch.py use_nav:=true use_slam:=true

Individual Node Launch
-----------------------

Run a single node:

::

    ros2 run <package> <executable>

Example - run control node:

::

    ros2 run control robot_control_node

Example - run perception node:

::

    ros2 run perception perception_node

Debugging Nodes
---------------

Run node with debugger attached:

::

    ros2 run --prefix 'gdb -ex run --args' <package> <executable>

Run node with verbose logging:

::

    ros2 run <package> <executable> --ros-args --log-level DEBUG

Firmware Development
====================

Create Firmware Workspace (One-Time Setup)
-------------------------------------------

::

    ros2 run micro_ros_setup create_firmware_ws.sh freertos esp32

Configure for Your Board
--------------------------

Configure target ESP32 and transport:

::

    ros2 run micro_ros_setup configure_firmware.sh esp32_controller \
      --transport udp \
      --ip 192.168.1.100 \
      --port 8888

Parameters:
- ``--transport``: ``udp`` or ``tcp`` (UDP recommended for WiFi)
- ``--ip``: IP of ROS 2 host/agent
- ``--port``: Port number

Build Firmware
---------------

::

    ros2 run micro_ros_setup build_firmware.sh

Build with verbose output:

::

    ros2 run micro_ros_setup build_firmware.sh --verbose

Flash to ESP32
---------------

Set serial port and flash:

::

    export ESPPORT=/dev/ttyUSB0
    ros2 run micro_ros_setup flash_firmware.sh

Monitor Serial Output
---------------------

View real-time firmware output:

::

    ros2 run micro_ros_setup monitor_serial.sh

Or use miniterm directly:

::

    python -m serial.tools.miniterm /dev/ttyUSB0 115200

ROS 2 Development Tools
=======================

Topic Monitoring
----------------

List all active topics:

::

    ros2 topic list

Show topic details (message type, publishers, subscribers):

::

    ros2 topic info /cmd_vel

Echo topic messages in real-time:

::

    ros2 topic echo /cmd_vel

Get topic message rate:

::

    ros2 topic hz /cmd_vel

Service Calls
-------------

List available services:

::

    ros2 service list

Call a service:

::

    ros2 service call /service_name service_type "{field: value}"

Parameter Management
---------------------

List parameters:

::

    ros2 param list

Get parameter value:

::

    ros2 param get /node_name param_name

Set parameter value:

::

    ros2 param set /node_name param_name value

Node Introspection
------------------

List running nodes:

::

    ros2 node list

View node information:

::

    ros2 node info /node_name

Visualization
=============

Starting RViz
--------------

Launch RViz visualization:

::

    rviz2

Load saved configuration:

::

    rviz2 -d config.rviz

Common RViz Displays
--------------------

- **TF**: Show coordinate frame transforms
- **Map**: Display occupancy grid or point clouds
- **Path**: Show planned paths
- **Marker**: Visualize custom messages
- **Image**: Display camera feeds

Testing
=======

Run All Tests
--------------

::

    colcon test

Test specific package:

::

    colcon test --packages-select control

View test results:

::

    colcon test-result --verbose

Unit Testing
-------------

Create test in ``test/`` directory following ROS 2 conventions:

::

    colcon build --packages-select <package> --cmake-args -DCMAKE_BUILD_TYPE=Debug
    ctest --output-on-failure

Integration Testing
-------------------

Test node interactions:

::

    # Terminal 1: Launch system
    ros2 launch system_launch.py
    
    # Terminal 2: Run integration tests
    colcon test --packages-select <package>

Common Commands Summary
=======================

+-------------------------------------+---------------------------------------+
| Task                                | Command                               |
+=====================================+=======================================+
| Start development environment       | ``docker compose up -d``              |
| Enter workspace                     | ``docker compose exec workspace bash``|
| Build all packages                  | ``colcon build``                      |
| Build specific package              | ``colcon build --packages-select pkg``|
| Launch Wall-E                       | ``ros2 launch wall_e_description ...``|
| Configure firmware                  | ``ros2 run micro_ros_setup config...``|
| Build firmware                      | ``ros2 run micro_ros_setup build...`` |
| Flash ESP32                         | ``ros2 run micro_ros_setup flash...`` |
| Monitor topics                      | ``ros2 topic echo /topic_name``       |
| List nodes                          | ``ros2 node list``                    |
| Run tests                           | ``colcon test``                       |
+-------------------------------------+---------------------------------------+

Tips and Tricks
===============

**Fast Rebuilds**: Use ``colcon build --parallel-workers N`` to speed up builds on multi-core systems.

**Incremental Builds**: Only rebuild changed packages: ``colcon build`` (colcon tracks dependencies).

**Clean Slate**: Remove ``build/``, ``install/``, and ``log/`` directories for a clean rebuild.

**Debugging Topics**: Use ``ros2 topic echo`` with ``--full-types`` for detailed message information.

**Memory Profiling**: Run nodes with ``-DCMAKE_BUILD_TYPE=Debug`` and use valgrind or AddressSanitizer.

**Parallel Testing**: ``colcon test --executor parallel`` for faster test execution.

**Logging**: Control verbosity with ``--ros-args --log-level DEBUG/INFO/WARN/ERROR``.

Related Documentation
======================

- :doc:`../getting_started/index` - Initial setup
- :doc:`../firmware/esp32_controller` - Firmware details
- :doc:`../variants/wall_e/index` - Wall-E development
- :doc:`../variants/gas_robot/index` - Gas Robot development
- :doc:`../references/troubleshooting` - Common issues

Troubleshooting
===============

**Build fails with missing packages:**

::

    colcon build --symlink-install --packages-up-to-regex ".*"

**Firmware won't compile:**

Check firmware workspace exists: ``ls firmware/PLATFORM firmware/APP``

**Serial port not accessible:**

Add your user to ``dialout`` group on host: ``sudo usermod -a -G dialout $USER``

**ROS 2 nodes can't communicate:**

Verify ``ROS_DOMAIN_ID`` is the same across all terminals

See :doc:`../references/troubleshooting` for more solutions.
