# generated from rosidl_generator_py/resource/_idl.py.em
# with input from multi_sensor_interfaces:srv/Multisensor.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Multisensor_Request(type):
    """Metaclass of message 'Multisensor_Request'."""

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
            module = import_type_support('multi_sensor_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'multi_sensor_interfaces.srv.Multisensor_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__multisensor__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__multisensor__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__multisensor__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__multisensor__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__multisensor__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Multisensor_Request(metaclass=Metaclass_Multisensor_Request):
    """Message class 'Multisensor_Request'."""

    __slots__ = [
        '_mid_finger',
        '_index_finger',
        '_ring_finger',
        '_location',
    ]

    _fields_and_field_types = {
        'mid_finger': 'float',
        'index_finger': 'float',
        'ring_finger': 'float',
        'location': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.mid_finger = kwargs.get('mid_finger', float())
        self.index_finger = kwargs.get('index_finger', float())
        self.ring_finger = kwargs.get('ring_finger', float())
        self.location = kwargs.get('location', str())

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
        if self.mid_finger != other.mid_finger:
            return False
        if self.index_finger != other.index_finger:
            return False
        if self.ring_finger != other.ring_finger:
            return False
        if self.location != other.location:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def mid_finger(self):
        """Message field 'mid_finger'."""
        return self._mid_finger

    @mid_finger.setter
    def mid_finger(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'mid_finger' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'mid_finger' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._mid_finger = value

    @builtins.property
    def index_finger(self):
        """Message field 'index_finger'."""
        return self._index_finger

    @index_finger.setter
    def index_finger(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'index_finger' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'index_finger' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._index_finger = value

    @builtins.property
    def ring_finger(self):
        """Message field 'ring_finger'."""
        return self._ring_finger

    @ring_finger.setter
    def ring_finger(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ring_finger' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'ring_finger' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._ring_finger = value

    @builtins.property
    def location(self):
        """Message field 'location'."""
        return self._location

    @location.setter
    def location(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'location' field must be of type 'str'"
        self._location = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Multisensor_Response(type):
    """Metaclass of message 'Multisensor_Response'."""

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
            module = import_type_support('multi_sensor_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'multi_sensor_interfaces.srv.Multisensor_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__multisensor__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__multisensor__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__multisensor__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__multisensor__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__multisensor__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Multisensor_Response(metaclass=Metaclass_Multisensor_Response):
    """Message class 'Multisensor_Response'."""

    __slots__ = [
        '_result',
    ]

    _fields_and_field_types = {
        'result': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.result = kwargs.get('result', int())

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
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'result' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'result' field must be an integer in [-2147483648, 2147483647]"
        self._result = value


class Metaclass_Multisensor(type):
    """Metaclass of service 'Multisensor'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('multi_sensor_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'multi_sensor_interfaces.srv.Multisensor')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__multisensor

            from multi_sensor_interfaces.srv import _multisensor
            if _multisensor.Metaclass_Multisensor_Request._TYPE_SUPPORT is None:
                _multisensor.Metaclass_Multisensor_Request.__import_type_support__()
            if _multisensor.Metaclass_Multisensor_Response._TYPE_SUPPORT is None:
                _multisensor.Metaclass_Multisensor_Response.__import_type_support__()


class Multisensor(metaclass=Metaclass_Multisensor):
    from multi_sensor_interfaces.srv._multisensor import Multisensor_Request as Request
    from multi_sensor_interfaces.srv._multisensor import Multisensor_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
