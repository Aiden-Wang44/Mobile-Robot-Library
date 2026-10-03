#include "mrl/Trajectory/Trajectory.hpp"
#include "mrl/Math/Angles.hpp"
//Uses linear interpolation for time based sampling
namespace mrl
{
  Trajectory::Trajectory(const std::vector<TrajectoryPoint> &points) : points_(points) {}
  const TrajectoryPoint &Trajectory::sampleByIndex(std::size_t index) const
  {
    return points_[index];
  }
  TrajectoryPoint Trajectory::sampleByTime(float time) const
  {

    if (time <= points_.front().time_)
    {
      return points_.front();
    }
    else if (time >= points_.back().time_)
    {
      return points_.back();
    }

    for (std::size_t i = 0; i < points_.size() - 1; i++)
    {
      if (time >= points_[i].time_ && time <= points_[i + 1].time_)
      {
        float t0 = points_[i].time_;
        float t1 = points_[i + 1].time_;
        float ratio = (time - t0) / (t1 - t0);
        const Pose &p0 = points_[i].pose_;
        const Pose &p1 = points_[i + 1].pose_;
        float x = p0.x + (p1.x - p0.x) * ratio;
        float y = p0.y + (p1.y - p0.y) * ratio;
        float heading = normalizeAngle(p0.heading + normalizeAngle(p1.heading - p0.heading) * ratio);
        float linearVelocity = points_[i].linearVelocity_ + (points_[i + 1].linearVelocity_ - points_[i].linearVelocity_) * ratio;
        float angularVelocity = points_[i].angularVelocity_ + (points_[i + 1].angularVelocity_ - points_[i].angularVelocity_) * ratio;
        return TrajectoryPoint(time, Pose(x, y, heading), linearVelocity, angularVelocity);
      }
    }
    return points_.back();
  }
  std::size_t Trajectory::getSize() const
  {
    return points_.size();
  }
  float Trajectory::getDuration() const
  {
    if (points_.empty())
    {
      return 0.0f;
    }
    else
    {
      return points_.back().time_ - points_.front().time_;
    }
  }

};