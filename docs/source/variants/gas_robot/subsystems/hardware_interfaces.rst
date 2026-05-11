====================
Hardware Interfaces
====================

Low-level drivers and interfaces for Gas Robot sensors and actuators.

Overview
========

The hardware interfaces layer provides abstraction for all physical hardware connected to Gas Robot, including gas sensors, motor controllers, and communication interfaces.

Supported Hardware
===================

Gas Sensors
-----------

- Gas detection modules with analog/digital output
- I2C and SPI sensor interfaces
- Real-time data acquisition and filtering

Motor Control
--------------

- PWM-based speed control
- Direction control via GPIO
- Encoder feedback for odometry

Communication Interfaces
------------------------

- I2C for sensor communication
- SPI for high-speed data transfer
- UART for serial communication
- USB for programming and debugging

Sensor Drivers
===============

Gas Sensor Driver
------------------

Reads from gas detection hardware and publishes calibrated values.

::

    Topic: /sensors/gas
    Type: custom_interfaces/GasSensorData
    Rate: 10 Hz

Motor Driver
-----------

Controls motor speed and direction.

::

    Service: /motor/set_speed
    Topic: /motor/feedback

Adding New Sensors
===================

To add a new sensor:

1. Create driver node in ``hardware_interfaces/src/``
2. Define message types in ``robot_interfaces/msg/``
3. Register topic in communication layer
4. Add configuration in ``hardware_interfaces/config/sensors.yaml``

Configuration
==============

Hardware parameters are in ``gas_robot_ws/src/hardware_interfaces/config/sensors.yaml``:

::

    i2c_devices:
      - bus: 0
        address: 0x68
        sensor: gas_detector
    
    motor_pins:
      left_pwm: 12
      left_dir: 13
      right_pwm: 14
      right_dir: 15

Troubleshooting
===============

**Sensor not detected**: Check I2C address and bus configuration.

**Motor not responding**: Verify GPIO pin configuration and PWM frequency.

**Data corruption**: Check cable shielding and power supply voltage.

See :doc:`../../references/troubleshooting` for common issues.

Related Documentation
======================

- :doc:`communication` - Inter-node messaging
- :doc:`perception` - Sensor data processing
- :doc:`../index` - Gas Robot variant overview
- :doc:`../../firmware/esp32_controller` - Firmware hardware integration
- :doc:`../../hardware/architecture` - Platform architecture
