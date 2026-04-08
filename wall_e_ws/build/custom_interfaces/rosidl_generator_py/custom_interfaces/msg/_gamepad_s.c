// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from custom_interfaces:msg/Gamepad.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "custom_interfaces/msg/detail/gamepad__struct.h"
#include "custom_interfaces/msg/detail/gamepad__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool custom_interfaces__msg__gamepad__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[39];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("custom_interfaces.msg._gamepad.Gamepad", full_classname_dest, 38) == 0);
  }
  custom_interfaces__msg__Gamepad * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // left_stick_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_stick_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->left_stick_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // left_stick_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_stick_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->left_stick_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // right_stick_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_stick_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->right_stick_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // right_stick_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_stick_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->right_stick_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // left_trigger
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_trigger");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->left_trigger = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // right_trigger
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_trigger");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->right_trigger = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // dpad_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "dpad_x");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->dpad_x = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // dpad_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "dpad_y");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->dpad_y = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // a
    PyObject * field = PyObject_GetAttrString(_pymsg, "a");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->a = (Py_True == field);
    Py_DECREF(field);
  }
  {  // b
    PyObject * field = PyObject_GetAttrString(_pymsg, "b");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->b = (Py_True == field);
    Py_DECREF(field);
  }
  {  // x
    PyObject * field = PyObject_GetAttrString(_pymsg, "x");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->x = (Py_True == field);
    Py_DECREF(field);
  }
  {  // y
    PyObject * field = PyObject_GetAttrString(_pymsg, "y");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->y = (Py_True == field);
    Py_DECREF(field);
  }
  {  // lb
    PyObject * field = PyObject_GetAttrString(_pymsg, "lb");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->lb = (Py_True == field);
    Py_DECREF(field);
  }
  {  // rb
    PyObject * field = PyObject_GetAttrString(_pymsg, "rb");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->rb = (Py_True == field);
    Py_DECREF(field);
  }
  {  // back
    PyObject * field = PyObject_GetAttrString(_pymsg, "back");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->back = (Py_True == field);
    Py_DECREF(field);
  }
  {  // start
    PyObject * field = PyObject_GetAttrString(_pymsg, "start");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->start = (Py_True == field);
    Py_DECREF(field);
  }
  {  // home
    PyObject * field = PyObject_GetAttrString(_pymsg, "home");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->home = (Py_True == field);
    Py_DECREF(field);
  }
  {  // left_stick_press
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_stick_press");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->left_stick_press = (Py_True == field);
    Py_DECREF(field);
  }
  {  // right_stick_press
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_stick_press");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->right_stick_press = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * custom_interfaces__msg__gamepad__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Gamepad */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("custom_interfaces.msg._gamepad");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Gamepad");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  custom_interfaces__msg__Gamepad * ros_message = (custom_interfaces__msg__Gamepad *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_stick_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->left_stick_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_stick_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_stick_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->left_stick_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_stick_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_stick_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->right_stick_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_stick_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_stick_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->right_stick_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_stick_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_trigger
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->left_trigger);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_trigger", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_trigger
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->right_trigger);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_trigger", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dpad_x
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->dpad_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dpad_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dpad_y
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->dpad_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dpad_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->a ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // b
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->b ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "b", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // x
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->x ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->y ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lb
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->lb ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lb", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rb
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->rb ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rb", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // back
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->back ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "back", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // start
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->start ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "start", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // home
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->home ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "home", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_stick_press
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->left_stick_press ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_stick_press", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_stick_press
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->right_stick_press ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_stick_press", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
