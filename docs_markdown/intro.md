# Introduction

This project is a modular robotics workspace built around a single idea:

> Robots should not be rewritten per project — only reconfigured.

Instead of treating each robot as a standalone system, this workspace defines a shared foundation of firmware, communication contracts, and reusable subsystems, with robot-specific behavior layered on top.

## Design Philosophy

### Separation of concerns

Each layer has a strict responsibility:

- **Firmware (ESP32)** → hardware control and raw sensor access  
- **Platform (ROS 2)** → messaging, coordination, system-wide communication  
- **Subsystems** → reusable robotics intelligence (mapping, perception, estimation)  
- **Variants** → robot-specific behavior and mission logic  

No layer is allowed to bypass another.

### Message-first architecture

All system interaction happens through explicit message contracts.

There are no hidden function calls between layers.

Examples:

- `/cmd_vel` → motion intent
- `/imu/data` → inertial sensing
- `/odom` → estimated motion state
- `/gas_sensor/reading` → domain-specific sensing

Everything is observable, loggable, and replayable.

### Hardware abstraction

The ESP32 firmware is treated as a deterministic hardware adapter:

- sensors → ROS 2 messages
- commands → motor outputs
- no robot logic inside firmware

This ensures hardware can change without rewriting system behavior.

### Subsystem reusability

Subsystems are designed to be:

- robot-agnostic
- composable
- replaceable

For example:

- SLAM works for Wall-E and Gas Robot without modification
- perception pipelines are shared
- only inputs/outputs are remapped per variant

### Variant-driven behavior

Each robot is defined as a **behavior composition**, not a new codebase.

A variant defines:

- which subsystems are active
- how data is routed
- what mission logic runs on top

Example:

- Wall-E → teleoperation + feedback visualization
- Gas Robot → autonomous exploration + gas mapping

## System Overview

The full system is structured into four layers:

``` bash
Firmware Layer
↓
ROS 2 Communication Layer
↓
Subsystem Layer
↓
Variant Behavior Layer
```

Each layer is replaceable without modifying the others.

## Supported Robots

### Wall-E

A general-purpose robotics platform for:

- teleoperation
- sensor experimentation
- system debugging

### Gas Robot

A specialized autonomous platform for:

- gas detection
- environmental mapping
- exploration tasks

More variants can be added by extending the same contract system.

## Core Technology Stack

- ROS 2 Humble (communication + runtime)
- ESP32 (embedded control)
- FreeRTOS (firmware scheduling)
- micro-ROS (bridge layer)
- Docker (development environment)
- Sphinx / Markdown (documentation)

## Why this architecture exists

Traditional robotics projects fail to scale because:

- hardware and software are tightly coupled
- behavior logic is embedded in firmware
- subsystems are not reusable
- adding a new robot means rewriting everything

This workspace solves that by enforcing:

- strict interfaces
- shared subsystems
- variant-based composition

## Next Steps

Start with:

- `deployment/setup.md` → environment setup
- `platform/system_contract.md` → message definitions
- `variants/wall_e/index.md` → first robot stack
