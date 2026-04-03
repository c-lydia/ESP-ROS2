# ESP32 Controller

The ESP32 controller is the main FreeRTOS application running on the ESP32, handling sensor I/O and micro-ROS communication.

## Overview

The controller manages:

- **IMU (MPU6050):** Accelerometer and gyroscope data via I2C
- **Ultrasonic Sensor (HC-SR04):** Range/distance measurements
- **micro-ROS Agent:** UDP communication with the host ROS 2 system

## Hardware Configuration

### I2C (IMU)

- **SCL (GPIO 22):** Serial Clock
- **SDA (GPIO 21):** Serial Data
- **Device Address:** 0x68 (MPU6050)
- **Frequency:** 100 kHz

### Ultrasonic Sensor

- **Trigger Pin:** GPIO 9
- **Echo Pin:** GPIO 10

## Build and Flash

### Prerequisites

- ESP-IDF v5.0+
- micro-ROS firmware libraries
- FreeRTOS patched for micro-ROS

### Build Command

```bash
cd firmware/dev_ws
idf.py build
```

### Flash Command

```bash
idf.py flash
```

### Monitor Serial Output

```bash
idf.py monitor
```

## Code Structure

``` bash
firmware/freertos_apps/apps/esp32_controller/
├── app.c                 # Main application logic
└── app-colcon.meta       # Build configuration
```

### Main Functions

- **app_main():** Entry point, initializes WiFi, micro-ROS, sensors
- **imu_read():** Reads IMU data and publishes to ROS
- **range_read():** Measures distance and publishes to ROS
- **micro_ros_task():** Core communication loop

## ROS Publishers

| Topic | Message Type | Description |
|-------|--------------|-------------|
| `/imu` | `sensor_msgs::msg::Imu` | 6-axis IMU data (accel + gyro) |
| `/range` | `sensor_msgs::msg::Range` | Ultrasonic distance measurement |

## WiFi Configuration

```c
#define WIFI_SSID "i_need_to_sleep"
#define WIFI_PASS "12345678"
```

> **Note:** Update WiFi credentials in app.c before building.

## Troubleshooting

### I2C Communication Fails

- Check pull-up resistors on SCL/SDA
- Verify I2C frequency (100 kHz default)
- Confirm MPU6050 address matches (0x68)

### Ultrasonic Measurements Are Erratic

- Ensure GPIO 9/10 are not used elsewhere
- Check sensor power supply (5V recommended)
- Verify echo pin is connected to an ADC-capable GPIO

### micro-ROS Connection Issues

- Confirm WiFi SSID/password
- Check micro-ROS agent is running (`docker compose up`)
- Verify UDP port 9999 is accessible

## Future Enhancements

- [ ] Add magnetometer (compass) support
- [ ] Implement sensor fusion (Kalman filter)
- [ ] Add servo/motor control
- [ ] SD card logging for offline recording
