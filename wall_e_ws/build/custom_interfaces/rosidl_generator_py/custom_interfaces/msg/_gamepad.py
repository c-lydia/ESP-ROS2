# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_interfaces:msg/Gamepad.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Gamepad(type):
    """Metaclass of message 'Gamepad'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_interfaces.msg.Gamepad')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gamepad
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gamepad
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gamepad
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gamepad
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gamepad

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Gamepad(metaclass=Metaclass_Gamepad):
    """Message class 'Gamepad'."""

    __slots__ = [
        '_header',
        '_left_stick_x',
        '_left_stick_y',
        '_right_stick_x',
        '_right_stick_y',
        '_left_trigger',
        '_right_trigger',
        '_dpad_x',
        '_dpad_y',
        '_a',
        '_b',
        '_x',
        '_y',
        '_lb',
        '_rb',
        '_back',
        '_start',
        '_home',
        '_left_stick_press',
        '_right_stick_press',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'left_stick_x': 'float',
        'left_stick_y': 'float',
        'right_stick_x': 'float',
        'right_stick_y': 'float',
        'left_trigger': 'float',
        'right_trigger': 'float',
        'dpad_x': 'int8',
        'dpad_y': 'int8',
        'a': 'boolean',
        'b': 'boolean',
        'x': 'boolean',
        'y': 'boolean',
        'lb': 'boolean',
        'rb': 'boolean',
        'back': 'boolean',
        'start': 'boolean',
        'home': 'boolean',
        'left_stick_press': 'boolean',
        'right_stick_press': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.left_stick_x = kwargs.get('left_stick_x', float())
        self.left_stick_y = kwargs.get('left_stick_y', float())
        self.right_stick_x = kwargs.get('right_stick_x', float())
        self.right_stick_y = kwargs.get('right_stick_y', float())
        self.left_trigger = kwargs.get('left_trigger', float())
        self.right_trigger = kwargs.get('right_trigger', float())
        self.dpad_x = kwargs.get('dpad_x', int())
        self.dpad_y = kwargs.get('dpad_y', int())
        self.a = kwargs.get('a', bool())
        self.b = kwargs.get('b', bool())
        self.x = kwargs.get('x', bool())
        self.y = kwargs.get('y', bool())
        self.lb = kwargs.get('lb', bool())
        self.rb = kwargs.get('rb', bool())
        self.back = kwargs.get('back', bool())
        self.start = kwargs.get('start', bool())
        self.home = kwargs.get('home', bool())
        self.left_stick_press = kwargs.get('left_stick_press', bool())
        self.right_stick_press = kwargs.get('right_stick_press', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.left_stick_x != other.left_stick_x:
            return False
        if self.left_stick_y != other.left_stick_y:
            return False
        if self.right_stick_x != other.right_stick_x:
            return False
        if self.right_stick_y != other.right_stick_y:
            return False
        if self.left_trigger != other.left_trigger:
            return False
        if self.right_trigger != other.right_trigger:
            return False
        if self.dpad_x != other.dpad_x:
            return False
        if self.dpad_y != other.dpad_y:
            return False
        if self.a != other.a:
            return False
        if self.b != other.b:
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.lb != other.lb:
            return False
        if self.rb != other.rb:
            return False
        if self.back != other.back:
            return False
        if self.start != other.start:
            return False
        if self.home != other.home:
            return False
        if self.left_stick_press != other.left_stick_press:
            return False
        if self.right_stick_press != other.right_stick_press:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def left_stick_x(self):
        """Message field 'left_stick_x'."""
        return self._left_stick_x

    @left_stick_x.setter
    def left_stick_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'left_stick_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'left_stick_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._left_stick_x = value

    @builtins.property
    def left_stick_y(self):
        """Message field 'left_stick_y'."""
        return self._left_stick_y

    @left_stick_y.setter
    def left_stick_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'left_stick_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'left_stick_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._left_stick_y = value

    @builtins.property
    def right_stick_x(self):
        """Message field 'right_stick_x'."""
        return self._right_stick_x

    @right_stick_x.setter
    def right_stick_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'right_stick_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'right_stick_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._right_stick_x = value

    @builtins.property
    def right_stick_y(self):
        """Message field 'right_stick_y'."""
        return self._right_stick_y

    @right_stick_y.setter
    def right_stick_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'right_stick_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'right_stick_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._right_stick_y = value

    @builtins.property
    def left_trigger(self):
        """Message field 'left_trigger'."""
        return self._left_trigger

    @left_trigger.setter
    def left_trigger(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'left_trigger' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'left_trigger' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._left_trigger = value

    @builtins.property
    def right_trigger(self):
        """Message field 'right_trigger'."""
        return self._right_trigger

    @right_trigger.setter
    def right_trigger(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'right_trigger' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'right_trigger' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._right_trigger = value

    @builtins.property
    def dpad_x(self):
        """Message field 'dpad_x'."""
        return self._dpad_x

    @dpad_x.setter
    def dpad_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'dpad_x' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'dpad_x' field must be an integer in [-128, 127]"
        self._dpad_x = value

    @builtins.property
    def dpad_y(self):
        """Message field 'dpad_y'."""
        return self._dpad_y

    @dpad_y.setter
    def dpad_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'dpad_y' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'dpad_y' field must be an integer in [-128, 127]"
        self._dpad_y = value

    @builtins.property
    def a(self):
        """Message field 'a'."""
        return self._a

    @a.setter
    def a(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'a' field must be of type 'bool'"
        self._a = value

    @builtins.property
    def b(self):
        """Message field 'b'."""
        return self._b

    @b.setter
    def b(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'b' field must be of type 'bool'"
        self._b = value

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'x' field must be of type 'bool'"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'y' field must be of type 'bool'"
        self._y = value

    @builtins.property
    def lb(self):
        """Message field 'lb'."""
        return self._lb

    @lb.setter
    def lb(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'lb' field must be of type 'bool'"
        self._lb = value

    @builtins.property
    def rb(self):
        """Message field 'rb'."""
        return self._rb

    @rb.setter
    def rb(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'rb' field must be of type 'bool'"
        self._rb = value

    @builtins.property
    def back(self):
        """Message field 'back'."""
        return self._back

    @back.setter
    def back(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'back' field must be of type 'bool'"
        self._back = value

    @builtins.property
    def start(self):
        """Message field 'start'."""
        return self._start

    @start.setter
    def start(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'start' field must be of type 'bool'"
        self._start = value

    @builtins.property
    def home(self):
        """Message field 'home'."""
        return self._home

    @home.setter
    def home(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'home' field must be of type 'bool'"
        self._home = value

    @builtins.property
    def left_stick_press(self):
        """Message field 'left_stick_press'."""
        return self._left_stick_press

    @left_stick_press.setter
    def left_stick_press(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'left_stick_press' field must be of type 'bool'"
        self._left_stick_press = value

    @builtins.property
    def right_stick_press(self):
        """Message field 'right_stick_press'."""
        return self._right_stick_press

    @right_stick_press.setter
    def right_stick_press(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'right_stick_press' field must be of type 'bool'"
        self._right_stick_press = value
