#pragma once
#include "mrl/Trajectory/TrajectoryPoint.hpp"
#include <vector>
namespace mrl
{
  class Trajectory
  {
  private:
    std::vector<TrajectoryPoint> points_;

  public:
    explicit Trajectory(const std::vector<TrajectoryPoint> &points);
    const TrajectoryPoint &sampleByIndex(std::size_t index) const;
    TrajectoryPoint sampleByTime(float time) const;
    std::size_t getSize() const;
    float getDuration() const;
  };

}