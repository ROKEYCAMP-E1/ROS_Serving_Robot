// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros_study_msgs:msg/MoveRobot.idl
// generated code does not contain a copyright notice

#ifndef ROS_STUDY_MSGS__MSG__DETAIL__MOVE_ROBOT__TRAITS_HPP_
#define ROS_STUDY_MSGS__MSG__DETAIL__MOVE_ROBOT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros_study_msgs/msg/detail/move_robot__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros_study_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MoveRobot & msg,
  std::ostream & out)
{
  out << "{";
  // member: topic_move_robot
  {
    out << "topic_move_robot: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_move_robot, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveRobot & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: topic_move_robot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "topic_move_robot: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_move_robot, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveRobot & msg, bool use_flow_style = false)
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

}  // namespace ros_study_msgs

namespace rosidl_generator_traits
{

[[deprecated("use ros_study_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros_study_msgs::msg::MoveRobot & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros_study_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros_study_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ros_study_msgs::msg::MoveRobot & msg)
{
  return ros_study_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ros_study_msgs::msg::MoveRobot>()
{
  return "ros_study_msgs::msg::MoveRobot";
}

template<>
inline const char * name<ros_study_msgs::msg::MoveRobot>()
{
  return "ros_study_msgs/msg/MoveRobot";
}

template<>
struct has_fixed_size<ros_study_msgs::msg::MoveRobot>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros_study_msgs::msg::MoveRobot>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros_study_msgs::msg::MoveRobot>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS_STUDY_MSGS__MSG__DETAIL__MOVE_ROBOT__TRAITS_HPP_
