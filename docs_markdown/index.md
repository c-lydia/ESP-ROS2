# Robotics Workspace

A modular robotics platform built on ROS 2, ESP32 firmware, and reusable subsystem architecture.

This system supports multiple robot variants including:

- Wall-E (teleoperated / research platform)
- Gas Robot (autonomous sensing & exploration)

## Core Idea

Instead of building robots as isolated projects, this workspace defines:

- a shared communication contract
- reusable subsystems
- swappable robot behaviors
- consistent firmware interface

## System Layers

- **Firmware Layer** → ESP32 + FreeRTOS + micro-ROS
- **Platform Layer** → ROS 2 + messaging contracts
- **Subsystem Layer** → perception, mapping, estimation
- **Variant Layer** → robot-specific behavior stacks

## Documentation Map

### Platform

- system contracts
- communication model
- messaging rules

### Firmware

- ESP32 controller
- sensors and motors
- micro-ROS bridge

### ROS 2

- topics, services, actions
- TF tree
- navigation stack

### Subsystems

- perception
- state estimation
- mapping
- navigation

### Variants

- Wall-E
- Gas Robot

## Getting Started

Start here:

1. `intro.md`
2. `deployment/setup.md`
3. `variants/wall_e/index.md`
