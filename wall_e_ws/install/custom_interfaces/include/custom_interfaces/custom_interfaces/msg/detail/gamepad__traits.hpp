// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:msg/Gamepad.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__GAMEPAD__TRAITS_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__GAMEPAD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/msg/detail/gamepad__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace custom_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Gamepad & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: left_stick_x
  {
    out << "left_stick_x: ";
    rosidl_generator_traits::value_to_yaml(msg.left_stick_x, out);
    out << ", ";
  }

  // member: left_stick_y
  {
    out << "left_stick_y: ";
    rosidl_generator_traits::value_to_yaml(msg.left_stick_y, out);
    out << ", ";
  }

  // member: right_stick_x
  {
    out << "right_stick_x: ";
    rosidl_generator_traits::value_to_yaml(msg.right_stick_x, out);
    out << ", ";
  }

  // member: right_stick_y
  {
    out << "right_stick_y: ";
    rosidl_generator_traits::value_to_yaml(msg.right_stick_y, out);
    out << ", ";
  }

  // member: left_trigger
  {
    out << "left_trigger: ";
    rosidl_generator_traits::value_to_yaml(msg.left_trigger, out);
    out << ", ";
  }

  // member: right_trigger
  {
    out << "right_trigger: ";
    rosidl_generator_traits::value_to_yaml(msg.right_trigger, out);
    out << ", ";
  }

  // member: dpad_x
  {
    out << "dpad_x: ";
    rosidl_generator_traits::value_to_yaml(msg.dpad_x, out);
    out << ", ";
  }

  // member: dpad_y
  {
    out << "dpad_y: ";
    rosidl_generator_traits::value_to_yaml(msg.dpad_y, out);
    out << ", ";
  }

  // member: a
  {
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: lb
  {
    out << "lb: ";
    rosidl_generator_traits::value_to_yaml(msg.lb, out);
    out << ", ";
  }

  // member: rb
  {
    out << "rb: ";
    rosidl_generator_traits::value_to_yaml(msg.rb, out);
    out << ", ";
  }

  // member: back
  {
    out << "back: ";
    rosidl_generator_traits::value_to_yaml(msg.back, out);
    out << ", ";
  }

  // member: start
  {
    out << "start: ";
    rosidl_generator_traits::value_to_yaml(msg.start, out);
    out << ", ";
  }

  // member: home
  {
    out << "home: ";
    rosidl_generator_traits::value_to_yaml(msg.home, out);
    out << ", ";
  }

  // member: left_stick_press
  {
    out << "left_stick_press: ";
    rosidl_generator_traits::value_to_yaml(msg.left_stick_press, out);
    out << ", ";
  }

  // member: right_stick_press
  {
    out << "right_stick_press: ";
    rosidl_generator_traits::value_to_yaml(msg.right_stick_press, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Gamepad & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: left_stick_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_stick_x: ";
    rosidl_generator_traits::value_to_yaml(msg.left_stick_x, out);
    out << "\n";
  }

  // member: left_stick_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_stick_y: ";
    rosidl_generator_traits::value_to_yaml(msg.left_stick_y, out);
    out << "\n";
  }

  // member: right_stick_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_stick_x: ";
    rosidl_generator_traits::value_to_yaml(msg.right_stick_x, out);
    out << "\n";
  }

  // member: right_stick_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_stick_y: ";
    rosidl_generator_traits::value_to_yaml(msg.right_stick_y, out);
    out << "\n";
  }

  // member: left_trigger
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_trigger: ";
    rosidl_generator_traits::value_to_yaml(msg.left_trigger, out);
    out << "\n";
  }

  // member: right_trigger
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_trigger: ";
    rosidl_generator_traits::value_to_yaml(msg.right_trigger, out);
    out << "\n";
  }

  // member: dpad_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dpad_x: ";
    rosidl_generator_traits::value_to_yaml(msg.dpad_x, out);
    out << "\n";
  }

  // member: dpad_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dpad_y: ";
    rosidl_generator_traits::value_to_yaml(msg.dpad_y, out);
    out << "\n";
  }

  // member: a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << "\n";
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: lb
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lb: ";
    rosidl_generator_traits::value_to_yaml(msg.lb, out);
    out << "\n";
  }

  // member: rb
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rb: ";
    rosidl_generator_traits::value_to_yaml(msg.rb, out);
    out << "\n";
  }

  // member: back
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "back: ";
    rosidl_generator_traits::value_to_yaml(msg.back, out);
    out << "\n";
  }

  // member: start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start: ";
    rosidl_generator_traits::value_to_yaml(msg.start, out);
    out << "\n";
  }

  // member: home
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "home: ";
    rosidl_generator_traits::value_to_yaml(msg.home, out);
    out << "\n";
  }

  // member: left_stick_press
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_stick_press: ";
    rosidl_generator_traits::value_to_yaml(msg.left_stick_press, out);
    out << "\n";
  }

  // member: right_stick_press
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_stick_press: ";
    rosidl_generator_traits::value_to_yaml(msg.right_stick_press, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Gamepad & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::msg::Gamepad & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::msg::Gamepad & msg)
{
  return custom_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::msg::Gamepad>()
{
  return "custom_interfaces::msg::Gamepad";
}

template<>
inline const char * name<custom_interfaces::msg::Gamepad>()
{
  return "custom_interfaces/msg/Gamepad";
}

template<>
struct has_fixed_size<custom_interfaces::msg::Gamepad>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<custom_interfaces::msg::Gamepad>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<custom_interfaces::msg::Gamepad>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__GAMEPAD__TRAITS_HPP_
