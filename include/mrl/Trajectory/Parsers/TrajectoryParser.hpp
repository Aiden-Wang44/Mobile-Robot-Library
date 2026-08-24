#pragma once
#include "mrl/Trajectory/Trajectory.hpp"
namespace mrl
{
  class TrajectoryParser
  {
  public:
    virtual ~TrajectoryParser() = default;
    virtual Trajectory parse(const char *filePath) const = 0;
  };
}