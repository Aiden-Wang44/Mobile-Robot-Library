#pragma once
#include "mrl/Utilities/Geometry/Pose.hpp"
namespace mrl
{
  class OdometryModel
  {
  public:
    virtual ~OdometryModel() = default;
    virtual DeltaPose update() = 0;
  };

}