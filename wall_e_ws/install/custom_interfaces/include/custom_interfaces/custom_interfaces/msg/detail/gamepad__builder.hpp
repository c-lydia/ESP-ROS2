// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/Gamepad.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__GAMEPAD__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__GAMEPAD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/gamepad__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_Gamepad_right_stick_press
{
public:
  explicit Init_Gamepad_right_stick_press(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::Gamepad right_stick_press(::custom_interfaces::msg::Gamepad::_right_stick_press_type arg)
  {
    msg_.right_stick_press = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_left_stick_press
{
public:
  explicit Init_Gamepad_left_stick_press(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  Init_Gamepad_right_stick_press left_stick_press(::custom_interfaces::msg::Gamepad::_left_stick_press_type arg)
  {
    msg_.left_stick_press = std::move(arg);
    return Init_Gamepad_right_stick_press(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_home
{
public:
  explicit Init_Gamepad_home(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  Init_Gamepad_left_stick_press home(::custom_interfaces::msg::Gamepad::_home_type arg)
  {
    msg_.home = std::move(arg);
    return Init_Gamepad_left_stick_press(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_start
{
public:
  explicit Init_Gamepad_start(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  Init_Gamepad_home start(::custom_interfaces::msg::Gamepad::_start_type arg)
  {
    msg_.start = std::move(arg);
    return Init_Gamepad_home(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_back
{
public:
  explicit Init_Gamepad_back(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  Init_Gamepad_start back(::custom_interfaces::msg::Gamepad::_back_type arg)
  {
    msg_.back = std::move(arg);
    return Init_Gamepad_start(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_rb
{
public:
  explicit Init_Gamepad_rb(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  Init_Gamepad_back rb(::custom_interfaces::msg::Gamepad::_rb_type arg)
  {
    msg_.rb = std::move(arg);
    return Init_Gamepad_back(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_lb
{
public:
  explicit Init_Gamepad_lb(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  Init_Gamepad_rb lb(::custom_interfaces::msg::Gamepad::_lb_type arg)
  {
    msg_.lb = std::move(arg);
    return Init_Gamepad_rb(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_y
{
public:
  explicit Init_Gamepad_y(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  Init_Gamepad_lb y(::custom_interfaces::msg::Gamepad::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Gamepad_lb(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_x
{
public:
  explicit Init_Gamepad_x(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  Init_Gamepad_y x(::custom_interfaces::msg::Gamepad::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Gamepad_y(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_b
{
public:
  explicit Init_Gamepad_b(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  Init_Gamepad_x b(::custom_interfaces::msg::Gamepad::_b_type arg)
  {
    msg_.b = std::move(arg);
    return Init_Gamepad_x(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_a
{
public:
  explicit Init_Gamepad_a(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  Init_Gamepad_b a(::custom_interfaces::msg::Gamepad::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_Gamepad_b(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_dpad_y
{
public:
  explicit Init_Gamepad_dpad_y(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  Init_Gamepad_a dpad_y(::custom_interfaces::msg::Gamepad::_dpad_y_type arg)
  {
    msg_.dpad_y = std::move(arg);
    return Init_Gamepad_a(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_dpad_x
{
public:
  explicit Init_Gamepad_dpad_x(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  Init_Gamepad_dpad_y dpad_x(::custom_interfaces::msg::Gamepad::_dpad_x_type arg)
  {
    msg_.dpad_x = std::move(arg);
    return Init_Gamepad_dpad_y(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_right_trigger
{
public:
  explicit Init_Gamepad_right_trigger(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  Init_Gamepad_dpad_x right_trigger(::custom_interfaces::msg::Gamepad::_right_trigger_type arg)
  {
    msg_.right_trigger = std::move(arg);
    return Init_Gamepad_dpad_x(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_left_trigger
{
public:
  explicit Init_Gamepad_left_trigger(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  Init_Gamepad_right_trigger left_trigger(::custom_interfaces::msg::Gamepad::_left_trigger_type arg)
  {
    msg_.left_trigger = std::move(arg);
    return Init_Gamepad_right_trigger(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_right_stick_y
{
public:
  explicit Init_Gamepad_right_stick_y(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  Init_Gamepad_left_trigger right_stick_y(::custom_interfaces::msg::Gamepad::_right_stick_y_type arg)
  {
    msg_.right_stick_y = std::move(arg);
    return Init_Gamepad_left_trigger(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_right_stick_x
{
public:
  explicit Init_Gamepad_right_stick_x(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  Init_Gamepad_right_stick_y right_stick_x(::custom_interfaces::msg::Gamepad::_right_stick_x_type arg)
  {
    msg_.right_stick_x = std::move(arg);
    return Init_Gamepad_right_stick_y(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_left_stick_y
{
public:
  explicit Init_Gamepad_left_stick_y(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  Init_Gamepad_right_stick_x left_stick_y(::custom_interfaces::msg::Gamepad::_left_stick_y_type arg)
  {
    msg_.left_stick_y = std::move(arg);
    return Init_Gamepad_right_stick_x(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_left_stick_x
{
public:
  explicit Init_Gamepad_left_stick_x(::custom_interfaces::msg::Gamepad & msg)
  : msg_(msg)
  {}
  Init_Gamepad_left_stick_y left_stick_x(::custom_interfaces::msg::Gamepad::_left_stick_x_type arg)
  {
    msg_.left_stick_x = std::move(arg);
    return Init_Gamepad_left_stick_y(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

class Init_Gamepad_header
{
public:
  Init_Gamepad_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Gamepad_left_stick_x header(::custom_interfaces::msg::Gamepad::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Gamepad_left_stick_x(msg_);
  }

private:
  ::custom_interfaces::msg::Gamepad msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::Gamepad>()
{
  return custom_interfaces::msg::builder::Init_Gamepad_header();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__GAMEPAD__BUILDER_HPP_
