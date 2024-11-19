# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ros_study_msgs:srv/OrderCustomer.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'menu_num'
# Member 'quantity_num'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_OrderCustomer_Request(type):
    """Metaclass of message 'OrderCustomer_Request'."""

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
            module = import_type_support('ros_study_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros_study_msgs.srv.OrderCustomer_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__order_customer__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__order_customer__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__order_customer__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__order_customer__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__order_customer__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class OrderCustomer_Request(metaclass=Metaclass_OrderCustomer_Request):
    """Message class 'OrderCustomer_Request'."""

    __slots__ = [
        '_menu_num',
        '_quantity_num',
        '_table_number',
        '_order_round',
    ]

    _fields_and_field_types = {
        'menu_num': 'sequence<int32>',
        'quantity_num': 'sequence<int32>',
        'table_number': 'int8',
        'order_round': 'int8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.menu_num = array.array('i', kwargs.get('menu_num', []))
        self.quantity_num = array.array('i', kwargs.get('quantity_num', []))
        self.table_number = kwargs.get('table_number', int())
        self.order_round = kwargs.get('order_round', int())

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
        if self.menu_num != other.menu_num:
            return False
        if self.quantity_num != other.quantity_num:
            return False
        if self.table_number != other.table_number:
            return False
        if self.order_round != other.order_round:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def menu_num(self):
        """Message field 'menu_num'."""
        return self._menu_num

    @menu_num.setter
    def menu_num(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'menu_num' array.array() must have the type code of 'i'"
            self._menu_num = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'menu_num' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._menu_num = array.array('i', value)

    @builtins.property
    def quantity_num(self):
        """Message field 'quantity_num'."""
        return self._quantity_num

    @quantity_num.setter
    def quantity_num(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'quantity_num' array.array() must have the type code of 'i'"
            self._quantity_num = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'quantity_num' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._quantity_num = array.array('i', value)

    @builtins.property
    def table_number(self):
        """Message field 'table_number'."""
        return self._table_number

    @table_number.setter
    def table_number(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'table_number' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'table_number' field must be an integer in [-128, 127]"
        self._table_number = value

    @builtins.property
    def order_round(self):
        """Message field 'order_round'."""
        return self._order_round

    @order_round.setter
    def order_round(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'order_round' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'order_round' field must be an integer in [-128, 127]"
        self._order_round = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_OrderCustomer_Response(type):
    """Metaclass of message 'OrderCustomer_Response'."""

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
            module = import_type_support('ros_study_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros_study_msgs.srv.OrderCustomer_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__order_customer__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__order_customer__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__order_customer__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__order_customer__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__order_customer__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class OrderCustomer_Response(metaclass=Metaclass_OrderCustomer_Response):
    """Message class 'OrderCustomer_Response'."""

    __slots__ = [
        '_order_check',
    ]

    _fields_and_field_types = {
        'order_check': 'int8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.order_check = kwargs.get('order_check', int())

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
        if self.order_check != other.order_check:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def order_check(self):
        """Message field 'order_check'."""
        return self._order_check

    @order_check.setter
    def order_check(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'order_check' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'order_check' field must be an integer in [-128, 127]"
        self._order_check = value


class Metaclass_OrderCustomer(type):
    """Metaclass of service 'OrderCustomer'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ros_study_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros_study_msgs.srv.OrderCustomer')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__order_customer

            from ros_study_msgs.srv import _order_customer
            if _order_customer.Metaclass_OrderCustomer_Request._TYPE_SUPPORT is None:
                _order_customer.Metaclass_OrderCustomer_Request.__import_type_support__()
            if _order_customer.Metaclass_OrderCustomer_Response._TYPE_SUPPORT is None:
                _order_customer.Metaclass_OrderCustomer_Response.__import_type_support__()


class OrderCustomer(metaclass=Metaclass_OrderCustomer):
    from ros_study_msgs.srv._order_customer import OrderCustomer_Request as Request
    from ros_study_msgs.srv._order_customer import OrderCustomer_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
