#pragma once
#include "mrl/Utilities/Geometry/Pose.hpp"
namespace mrl
{
  struct TrajectoryPoint
  {
    float time_;
    Pose pose_;
    float linearVelocity_;
    float angularVelocity_;
    TrajectoryPoint(float time, const Pose &pose, float linearVelocity, float angularVelocity) : time_(time), pose_(pose), linearVelocity_(linearVelocity), angularVelocity_(angularVelocity)
    {
    }
  };
}