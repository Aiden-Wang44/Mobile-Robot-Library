#include "mrl/Localizers/ConcreteLocalizers/SimpleLocalizer.hpp"
#include "mrl/Math/Angles.hpp"
#include <cmath>

namespace mrl
{
  SimpleLocalizer::SimpleLocalizer(
      OdometryModel &odometry)
      : odometry_(odometry)
  {
  }
  Pose SimpleLocalizer::getPose() const
  {
    return pose_;
  }
  void SimpleLocalizer::setPose(const Pose &pose)
  {
    pose_ = pose;
  }
  void SimpleLocalizer::reset()
  {
    pose_ = Pose(0.0f, 0.0f, 0.0f);
  }
  void SimpleLocalizer::update()
  {
    DeltaPose delta = odometry_.update();
    float midHeading = pose_.heading + delta.dtheta * 0.5f;
    float gx = delta.dx * std::cos(midHeading) - delta.dy * std::sin(midHeading);
    float gy = delta.dy * std::cos(midHeading) + delta.dx * std::sin(midHeading);
    pose_.x += gx;
    pose_.y += gy;
    pose_.heading = normalizeAngle(pose_.heading + delta.dtheta);
  }
}