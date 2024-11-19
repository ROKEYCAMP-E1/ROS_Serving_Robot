// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros_study_msgs:srv/OrderCustomer.idl
// generated code does not contain a copyright notice

#ifndef ROS_STUDY_MSGS__SRV__DETAIL__ORDER_CUSTOMER__TRAITS_HPP_
#define ROS_STUDY_MSGS__SRV__DETAIL__ORDER_CUSTOMER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros_study_msgs/srv/detail/order_customer__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros_study_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const OrderCustomer_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: menu_num
  {
    if (msg.menu_num.size() == 0) {
      out << "menu_num: []";
    } else {
      out << "menu_num: [";
      size_t pending_items = msg.menu_num.size();
      for (auto item : msg.menu_num) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: quantity_num
  {
    if (msg.quantity_num.size() == 0) {
      out << "quantity_num: []";
    } else {
      out << "quantity_num: [";
      size_t pending_items = msg.quantity_num.size();
      for (auto item : msg.quantity_num) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: table_number
  {
    out << "table_number: ";
    rosidl_generator_traits::value_to_yaml(msg.table_number, out);
    out << ", ";
  }

  // member: order_round
  {
    out << "order_round: ";
    rosidl_generator_traits::value_to_yaml(msg.order_round, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OrderCustomer_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: menu_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.menu_num.size() == 0) {
      out << "menu_num: []\n";
    } else {
      out << "menu_num:\n";
      for (auto item : msg.menu_num) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: quantity_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.quantity_num.size() == 0) {
      out << "quantity_num: []\n";
    } else {
      out << "quantity_num:\n";
      for (auto item : msg.quantity_num) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: table_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "table_number: ";
    rosidl_generator_traits::value_to_yaml(msg.table_number, out);
    out << "\n";
  }

  // member: order_round
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "order_round: ";
    rosidl_generator_traits::value_to_yaml(msg.order_round, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OrderCustomer_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros_study_msgs

namespace rosidl_generator_traits
{

[[deprecated("use ros_study_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros_study_msgs::srv::OrderCustomer_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros_study_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros_study_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros_study_msgs::srv::OrderCustomer_Request & msg)
{
  return ros_study_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros_study_msgs::srv::OrderCustomer_Request>()
{
  return "ros_study_msgs::srv::OrderCustomer_Request";
}

template<>
inline const char * name<ros_study_msgs::srv::OrderCustomer_Request>()
{
  return "ros_study_msgs/srv/OrderCustomer_Request";
}

template<>
struct has_fixed_size<ros_study_msgs::srv::OrderCustomer_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros_study_msgs::srv::OrderCustomer_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros_study_msgs::srv::OrderCustomer_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ros_study_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const OrderCustomer_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: order_check
  {
    out << "order_check: ";
    rosidl_generator_traits::value_to_yaml(msg.order_check, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OrderCustomer_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: order_check
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "order_check: ";
    rosidl_generator_traits::value_to_yaml(msg.order_check, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OrderCustomer_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros_study_msgs

namespace rosidl_generator_traits
{

[[deprecated("use ros_study_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros_study_msgs::srv::OrderCustomer_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros_study_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros_study_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros_study_msgs::srv::OrderCustomer_Response & msg)
{
  return ros_study_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros_study_msgs::srv::OrderCustomer_Response>()
{
  return "ros_study_msgs::srv::OrderCustomer_Response";
}

template<>
inline const char * name<ros_study_msgs::srv::OrderCustomer_Response>()
{
  return "ros_study_msgs/srv/OrderCustomer_Response";
}

template<>
struct has_fixed_size<ros_study_msgs::srv::OrderCustomer_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros_study_msgs::srv::OrderCustomer_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros_study_msgs::srv::OrderCustomer_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros_study_msgs::srv::OrderCustomer>()
{
  return "ros_study_msgs::srv::OrderCustomer";
}

template<>
inline const char * name<ros_study_msgs::srv::OrderCustomer>()
{
  return "ros_study_msgs/srv/OrderCustomer";
}

template<>
struct has_fixed_size<ros_study_msgs::srv::OrderCustomer>
  : std::integral_constant<
    bool,
    has_fixed_size<ros_study_msgs::srv::OrderCustomer_Request>::value &&
    has_fixed_size<ros_study_msgs::srv::OrderCustomer_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros_study_msgs::srv::OrderCustomer>
  : std::integral_constant<
    bool,
    has_bounded_size<ros_study_msgs::srv::OrderCustomer_Request>::value &&
    has_bounded_size<ros_study_msgs::srv::OrderCustomer_Response>::value
  >
{
};

template<>
struct is_service<ros_study_msgs::srv::OrderCustomer>
  : std::true_type
{
};

template<>
struct is_service_request<ros_study_msgs::srv::OrderCustomer_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros_study_msgs::srv::OrderCustomer_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS_STUDY_MSGS__SRV__DETAIL__ORDER_CUSTOMER__TRAITS_HPP_
