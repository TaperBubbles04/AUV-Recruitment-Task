// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from auv_interfaces:msg/BotPose.idl
// generated code does not contain a copyright notice

#ifndef AUV_INTERFACES__MSG__DETAIL__BOT_POSE__TRAITS_HPP_
#define AUV_INTERFACES__MSG__DETAIL__BOT_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "auv_interfaces/msg/detail/bot_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace auv_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const BotPose & msg,
  std::ostream & out)
{
  out << "{";
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

  // member: facing_direction
  {
    out << "facing_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.facing_direction, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BotPose & msg,
  std::ostream & out, size_t indentation = 0)
{
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

  // member: facing_direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "facing_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.facing_direction, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BotPose & msg, bool use_flow_style = false)
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

}  // namespace auv_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use auv_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const auv_interfaces::msg::BotPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  auv_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use auv_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const auv_interfaces::msg::BotPose & msg)
{
  return auv_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<auv_interfaces::msg::BotPose>()
{
  return "auv_interfaces::msg::BotPose";
}

template<>
inline const char * name<auv_interfaces::msg::BotPose>()
{
  return "auv_interfaces/msg/BotPose";
}

template<>
struct has_fixed_size<auv_interfaces::msg::BotPose>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<auv_interfaces::msg::BotPose>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<auv_interfaces::msg::BotPose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AUV_INTERFACES__MSG__DETAIL__BOT_POSE__TRAITS_HPP_
