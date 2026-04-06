# Wall-E

micro-ROS workspace for ESP32 (FreeRTOS + ESP-IDF) with ROS 2 Humble.

This repository includes:

- ESP32 firmware app: firmware/custom/esp32_controller
- micro-ROS firmware workspace: firmware/mcu_ws
- Host ROS 2 workspace: src, build, install
- micro-ROS agent container (UDP 9999)

## Prerequisites

- Docker
- Docker Compose
- USB access for flashing (device usually /dev/ttyUSB0)

## Quick Start

From the repository root:

1. Start workspace and agent

	docker compose up -d

2. Enter workspace container

	docker exec -it micro_ros_workspace bash

3. Build host ROS 2 workspace (if needed)

	cd /micro_ros_ws
	colcon build

4. Source the environment

	source /opt/ros/humble/setup.bash
	source /micro_ros_ws/install/setup.bash

## Build ESP32 Firmware

Inside the workspace container:

1. Configure firmware app and transport

``` bash
ros2 run micro_ros_setup configure_firmware.sh esp32_controller -t udp -i 192.168.1.2 -p 8888
```

2. Build firmware

``` bash
ros2 run micro_ros_setup build_firmware.sh
```

3. Firmware output files

``` bash
firmware/freertos_apps/microros_esp32_extensions/build/esp32_controller.bin
firmware/freertos_apps/microros_esp32_extensions/build/esp32_controller.elf
```

## Flash ESP32 Firmware

Inside the workspace container (requires serial device access):

1. Flash

``` bash
ros2 run micro_ros_setup flash_firmware.sh
```

If your board is not `/dev/ttyUSB0`, update `docker-compose.yaml` device mapping or run a custom docker command with the correct `--device` mapping.

## Run micro-ROS Agent

The compose service starts this automatically:

``` bash
microros/micro-ros-agent:humble udp4 --port 9999
```

You can check logs with:

``` bash
docker logs -f micro_ros_agent
```

## Useful Commands

- Rebuild host workspace

``` bash
docker exec -it micro_ros_workspace bash -lc "cd /micro_ros_ws && colcon build"
```

- Rebuild firmware

``` bash
docker exec -it micro_ros_workspace bash -lc "source /opt/ros/humble/setup.bash && source /micro_ros_ws/install/setup.bash && ros2 run micro_ros_setup build_firmware.sh"
```

- Stop everything

``` bash
docker compose down
```

## Troubleshooting

- Package `micro_ros_setup` not found
  Source both setup files:

``` bash
source /opt/ros/humble/setup.bash
source /micro_ros_ws/install/setup.bash
```

- Docker compose fails on `/dev/ttyUSB0`
  Your host may expose a different serial device. Adjust `docker-compose.yaml` accordingly.

- Build fails with Git safe.directory for esp-idf
  Run in container:

``` bash
git config --global --add safe.directory /micro_ros_ws/firmware/toolchain/esp-idf
```

## Project Layout

- `src`: ROS 2 packages
- `firmware/custom/esp32_controller: app source`
- `firmware/freertos_apps/microros_esp32_extensions`: generated ESP-IDF project
- `firmware/mcu_ws`: micro-ROS cross-compiled workspace
- `docs`: Sphinx documentation
