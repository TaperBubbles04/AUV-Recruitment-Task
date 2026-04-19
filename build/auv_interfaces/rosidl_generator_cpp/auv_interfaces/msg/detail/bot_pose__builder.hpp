// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auv_interfaces:msg/BotPose.idl
// generated code does not contain a copyright notice

#ifndef AUV_INTERFACES__MSG__DETAIL__BOT_POSE__BUILDER_HPP_
#define AUV_INTERFACES__MSG__DETAIL__BOT_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "auv_interfaces/msg/detail/bot_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace auv_interfaces
{

namespace msg
{

namespace builder
{

class Init_BotPose_facing_direction
{
public:
  explicit Init_BotPose_facing_direction(::auv_interfaces::msg::BotPose & msg)
  : msg_(msg)
  {}
  ::auv_interfaces::msg::BotPose facing_direction(::auv_interfaces::msg::BotPose::_facing_direction_type arg)
  {
    msg_.facing_direction = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auv_interfaces::msg::BotPose msg_;
};

class Init_BotPose_y
{
public:
  explicit Init_BotPose_y(::auv_interfaces::msg::BotPose & msg)
  : msg_(msg)
  {}
  Init_BotPose_facing_direction y(::auv_interfaces::msg::BotPose::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_BotPose_facing_direction(msg_);
  }

private:
  ::auv_interfaces::msg::BotPose msg_;
};

class Init_BotPose_x
{
public:
  Init_BotPose_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BotPose_y x(::auv_interfaces::msg::BotPose::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_BotPose_y(msg_);
  }

private:
  ::auv_interfaces::msg::BotPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auv_interfaces::msg::BotPose>()
{
  return auv_interfaces::msg::builder::Init_BotPose_x();
}

}  // namespace auv_interfaces

#endif  // AUV_INTERFACES__MSG__DETAIL__BOT_POSE__BUILDER_HPP_
