// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interfaces:msg/Gamepad.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/msg/detail/gamepad__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
custom_interfaces__msg__Gamepad__init(custom_interfaces__msg__Gamepad * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    custom_interfaces__msg__Gamepad__fini(msg);
    return false;
  }
  // left_stick_x
  // left_stick_y
  // right_stick_x
  // right_stick_y
  // left_trigger
  // right_trigger
  // dpad_x
  // dpad_y
  // a
  // b
  // x
  // y
  // lb
  // rb
  // back
  // start
  // home
  // left_stick_press
  // right_stick_press
  return true;
}

void
custom_interfaces__msg__Gamepad__fini(custom_interfaces__msg__Gamepad * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // left_stick_x
  // left_stick_y
  // right_stick_x
  // right_stick_y
  // left_trigger
  // right_trigger
  // dpad_x
  // dpad_y
  // a
  // b
  // x
  // y
  // lb
  // rb
  // back
  // start
  // home
  // left_stick_press
  // right_stick_press
}

bool
custom_interfaces__msg__Gamepad__are_equal(const custom_interfaces__msg__Gamepad * lhs, const custom_interfaces__msg__Gamepad * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // left_stick_x
  if (lhs->left_stick_x != rhs->left_stick_x) {
    return false;
  }
  // left_stick_y
  if (lhs->left_stick_y != rhs->left_stick_y) {
    return false;
  }
  // right_stick_x
  if (lhs->right_stick_x != rhs->right_stick_x) {
    return false;
  }
  // right_stick_y
  if (lhs->right_stick_y != rhs->right_stick_y) {
    return false;
  }
  // left_trigger
  if (lhs->left_trigger != rhs->left_trigger) {
    return false;
  }
  // right_trigger
  if (lhs->right_trigger != rhs->right_trigger) {
    return false;
  }
  // dpad_x
  if (lhs->dpad_x != rhs->dpad_x) {
    return false;
  }
  // dpad_y
  if (lhs->dpad_y != rhs->dpad_y) {
    return false;
  }
  // a
  if (lhs->a != rhs->a) {
    return false;
  }
  // b
  if (lhs->b != rhs->b) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // lb
  if (lhs->lb != rhs->lb) {
    return false;
  }
  // rb
  if (lhs->rb != rhs->rb) {
    return false;
  }
  // back
  if (lhs->back != rhs->back) {
    return false;
  }
  // start
  if (lhs->start != rhs->start) {
    return false;
  }
  // home
  if (lhs->home != rhs->home) {
    return false;
  }
  // left_stick_press
  if (lhs->left_stick_press != rhs->left_stick_press) {
    return false;
  }
  // right_stick_press
  if (lhs->right_stick_press != rhs->right_stick_press) {
    return false;
  }
  return true;
}

bool
custom_interfaces__msg__Gamepad__copy(
  const custom_interfaces__msg__Gamepad * input,
  custom_interfaces__msg__Gamepad * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // left_stick_x
  output->left_stick_x = input->left_stick_x;
  // left_stick_y
  output->left_stick_y = input->left_stick_y;
  // right_stick_x
  output->right_stick_x = input->right_stick_x;
  // right_stick_y
  output->right_stick_y = input->right_stick_y;
  // left_trigger
  output->left_trigger = input->left_trigger;
  // right_trigger
  output->right_trigger = input->right_trigger;
  // dpad_x
  output->dpad_x = input->dpad_x;
  // dpad_y
  output->dpad_y = input->dpad_y;
  // a
  output->a = input->a;
  // b
  output->b = input->b;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // lb
  output->lb = input->lb;
  // rb
  output->rb = input->rb;
  // back
  output->back = input->back;
  // start
  output->start = input->start;
  // home
  output->home = input->home;
  // left_stick_press
  output->left_stick_press = input->left_stick_press;
  // right_stick_press
  output->right_stick_press = input->right_stick_press;
  return true;
}

custom_interfaces__msg__Gamepad *
custom_interfaces__msg__Gamepad__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__Gamepad * msg = (custom_interfaces__msg__Gamepad *)allocator.allocate(sizeof(custom_interfaces__msg__Gamepad), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__msg__Gamepad));
  bool success = custom_interfaces__msg__Gamepad__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__msg__Gamepad__destroy(custom_interfaces__msg__Gamepad * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interfaces__msg__Gamepad__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interfaces__msg__Gamepad__Sequence__init(custom_interfaces__msg__Gamepad__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__Gamepad * data = NULL;

  if (size) {
    data = (custom_interfaces__msg__Gamepad *)allocator.zero_allocate(size, sizeof(custom_interfaces__msg__Gamepad), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__msg__Gamepad__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__msg__Gamepad__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_interfaces__msg__Gamepad__Sequence__fini(custom_interfaces__msg__Gamepad__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_interfaces__msg__Gamepad__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_interfaces__msg__Gamepad__Sequence *
custom_interfaces__msg__Gamepad__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__Gamepad__Sequence * array = (custom_interfaces__msg__Gamepad__Sequence *)allocator.allocate(sizeof(custom_interfaces__msg__Gamepad__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__msg__Gamepad__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interfaces__msg__Gamepad__Sequence__destroy(custom_interfaces__msg__Gamepad__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interfaces__msg__Gamepad__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interfaces__msg__Gamepad__Sequence__are_equal(const custom_interfaces__msg__Gamepad__Sequence * lhs, const custom_interfaces__msg__Gamepad__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__msg__Gamepad__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__msg__Gamepad__Sequence__copy(
  const custom_interfaces__msg__Gamepad__Sequence * input,
  custom_interfaces__msg__Gamepad__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__msg__Gamepad);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interfaces__msg__Gamepad * data =
      (custom_interfaces__msg__Gamepad *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__msg__Gamepad__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interfaces__msg__Gamepad__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interfaces__msg__Gamepad__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
