// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/Gamepad.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__GAMEPAD__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__GAMEPAD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/Gamepad in the package custom_interfaces.
typedef struct custom_interfaces__msg__Gamepad
{
  std_msgs__msg__Header header;
  float left_stick_x;
  float left_stick_y;
  float right_stick_x;
  float right_stick_y;
  float left_trigger;
  float right_trigger;
  int8_t dpad_x;
  int8_t dpad_y;
  bool a;
  bool b;
  bool x;
  bool y;
  bool lb;
  bool rb;
  bool back;
  bool start;
  bool home;
  bool left_stick_press;
  bool right_stick_press;
} custom_interfaces__msg__Gamepad;

// Struct for a sequence of custom_interfaces__msg__Gamepad.
typedef struct custom_interfaces__msg__Gamepad__Sequence
{
  custom_interfaces__msg__Gamepad * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__Gamepad__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__GAMEPAD__STRUCT_H_
