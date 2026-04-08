// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/Gamepad.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__GAMEPAD__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__GAMEPAD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__Gamepad __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__Gamepad __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Gamepad_
{
  using Type = Gamepad_<ContainerAllocator>;

  explicit Gamepad_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_stick_x = 0.0f;
      this->left_stick_y = 0.0f;
      this->right_stick_x = 0.0f;
      this->right_stick_y = 0.0f;
      this->left_trigger = 0.0f;
      this->right_trigger = 0.0f;
      this->dpad_x = 0;
      this->dpad_y = 0;
      this->a = false;
      this->b = false;
      this->x = false;
      this->y = false;
      this->lb = false;
      this->rb = false;
      this->back = false;
      this->start = false;
      this->home = false;
      this->left_stick_press = false;
      this->right_stick_press = false;
    }
  }

  explicit Gamepad_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_stick_x = 0.0f;
      this->left_stick_y = 0.0f;
      this->right_stick_x = 0.0f;
      this->right_stick_y = 0.0f;
      this->left_trigger = 0.0f;
      this->right_trigger = 0.0f;
      this->dpad_x = 0;
      this->dpad_y = 0;
      this->a = false;
      this->b = false;
      this->x = false;
      this->y = false;
      this->lb = false;
      this->rb = false;
      this->back = false;
      this->start = false;
      this->home = false;
      this->left_stick_press = false;
      this->right_stick_press = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _left_stick_x_type =
    float;
  _left_stick_x_type left_stick_x;
  using _left_stick_y_type =
    float;
  _left_stick_y_type left_stick_y;
  using _right_stick_x_type =
    float;
  _right_stick_x_type right_stick_x;
  using _right_stick_y_type =
    float;
  _right_stick_y_type right_stick_y;
  using _left_trigger_type =
    float;
  _left_trigger_type left_trigger;
  using _right_trigger_type =
    float;
  _right_trigger_type right_trigger;
  using _dpad_x_type =
    int8_t;
  _dpad_x_type dpad_x;
  using _dpad_y_type =
    int8_t;
  _dpad_y_type dpad_y;
  using _a_type =
    bool;
  _a_type a;
  using _b_type =
    bool;
  _b_type b;
  using _x_type =
    bool;
  _x_type x;
  using _y_type =
    bool;
  _y_type y;
  using _lb_type =
    bool;
  _lb_type lb;
  using _rb_type =
    bool;
  _rb_type rb;
  using _back_type =
    bool;
  _back_type back;
  using _start_type =
    bool;
  _start_type start;
  using _home_type =
    bool;
  _home_type home;
  using _left_stick_press_type =
    bool;
  _left_stick_press_type left_stick_press;
  using _right_stick_press_type =
    bool;
  _right_stick_press_type right_stick_press;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__left_stick_x(
    const float & _arg)
  {
    this->left_stick_x = _arg;
    return *this;
  }
  Type & set__left_stick_y(
    const float & _arg)
  {
    this->left_stick_y = _arg;
    return *this;
  }
  Type & set__right_stick_x(
    const float & _arg)
  {
    this->right_stick_x = _arg;
    return *this;
  }
  Type & set__right_stick_y(
    const float & _arg)
  {
    this->right_stick_y = _arg;
    return *this;
  }
  Type & set__left_trigger(
    const float & _arg)
  {
    this->left_trigger = _arg;
    return *this;
  }
  Type & set__right_trigger(
    const float & _arg)
  {
    this->right_trigger = _arg;
    return *this;
  }
  Type & set__dpad_x(
    const int8_t & _arg)
  {
    this->dpad_x = _arg;
    return *this;
  }
  Type & set__dpad_y(
    const int8_t & _arg)
  {
    this->dpad_y = _arg;
    return *this;
  }
  Type & set__a(
    const bool & _arg)
  {
    this->a = _arg;
    return *this;
  }
  Type & set__b(
    const bool & _arg)
  {
    this->b = _arg;
    return *this;
  }
  Type & set__x(
    const bool & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const bool & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__lb(
    const bool & _arg)
  {
    this->lb = _arg;
    return *this;
  }
  Type & set__rb(
    const bool & _arg)
  {
    this->rb = _arg;
    return *this;
  }
  Type & set__back(
    const bool & _arg)
  {
    this->back = _arg;
    return *this;
  }
  Type & set__start(
    const bool & _arg)
  {
    this->start = _arg;
    return *this;
  }
  Type & set__home(
    const bool & _arg)
  {
    this->home = _arg;
    return *this;
  }
  Type & set__left_stick_press(
    const bool & _arg)
  {
    this->left_stick_press = _arg;
    return *this;
  }
  Type & set__right_stick_press(
    const bool & _arg)
  {
    this->right_stick_press = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::Gamepad_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::Gamepad_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::Gamepad_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::Gamepad_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::Gamepad_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::Gamepad_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::Gamepad_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::Gamepad_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::Gamepad_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::Gamepad_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__Gamepad
    std::shared_ptr<custom_interfaces::msg::Gamepad_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__Gamepad
    std::shared_ptr<custom_interfaces::msg::Gamepad_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Gamepad_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->left_stick_x != other.left_stick_x) {
      return false;
    }
    if (this->left_stick_y != other.left_stick_y) {
      return false;
    }
    if (this->right_stick_x != other.right_stick_x) {
      return false;
    }
    if (this->right_stick_y != other.right_stick_y) {
      return false;
    }
    if (this->left_trigger != other.left_trigger) {
      return false;
    }
    if (this->right_trigger != other.right_trigger) {
      return false;
    }
    if (this->dpad_x != other.dpad_x) {
      return false;
    }
    if (this->dpad_y != other.dpad_y) {
      return false;
    }
    if (this->a != other.a) {
      return false;
    }
    if (this->b != other.b) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->lb != other.lb) {
      return false;
    }
    if (this->rb != other.rb) {
      return false;
    }
    if (this->back != other.back) {
      return false;
    }
    if (this->start != other.start) {
      return false;
    }
    if (this->home != other.home) {
      return false;
    }
    if (this->left_stick_press != other.left_stick_press) {
      return false;
    }
    if (this->right_stick_press != other.right_stick_press) {
      return false;
    }
    return true;
  }
  bool operator!=(const Gamepad_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Gamepad_

// alias to use template instance with default allocator
using Gamepad =
  custom_interfaces::msg::Gamepad_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__GAMEPAD__STRUCT_HPP_
