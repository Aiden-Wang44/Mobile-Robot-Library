#pragma once
#include "mrl/Utilities/Geometry/Pose.hpp"
namespace mrl
{
  class Localizer
  {
  public:
    virtual ~Localizer() = default;
    virtual Pose getPose() const = 0;
    virtual void setPose(const Pose &pose) = 0;
    virtual void reset() = 0;
    virtual void update() = 0;
  };
}