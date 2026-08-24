#include "mrl/Motion/ConcreteMotions/RamsetePathFollower.hpp"
#include "mrl/Math/Angles.hpp"
namespace mrl
{
  RamsetePathFollower::RamsetePathFollower(Localizer &localizer, Chassis &chassis, const Trajectory &trajectory, Timer &timer, RamseteParameters &ramseteParameters) : localizer_(localizer), chassis_(chassis), trajectory_(&trajectory), timer_(timer), ramseteParameters_(ramseteParameters) {}
  void RamsetePathFollower::update()
  {
    if (trajectory_ == nullptr)
    {
      return;
    }
    localizer_.update();
    float elapsedTime = timer_.getTime();
    TrajectoryPoint target = trajectory_->sampleByTime(elapsedTime);
    Pose p = localizer_.getPose();
    float globalErrorX = target.pose_.x - p.x;
    float globalErrorY = target.pose_.y - p.y;
    float globalErrorHeading = target.pose_.heading - p.heading;
    float localErrorX = globalErrorX * cos(p.heading) + globalErrorY * sin(p.heading);
    float localErrorY = globalErrorY * cos(p.heading) - globalErrorX * sin(p.heading);
    float localErrorHeading = normalizeAngle(globalErrorHeading);
    float vd = target.linearVelocity_;
    float wd = target.angularVelocity_;
    float k = 2.0f * ramseteParameters_.zeta_ * sqrt(wd * wd + ramseteParameters_.beta_ * vd * vd);
    float v = vd * cos(localErrorHeading) + k * localErrorX;
    float w = wd + k * localErrorHeading + ramseteParameters_.beta_ * vd * sinc(localErrorHeading) * localErrorY;

    chassis_.driveVelocity(v, 0.0f, w);
    if (elapsedTime >= trajectory_->getDuration())
    {
      finished_ = true;
    }
  }
  void RamsetePathFollower::setTarget(const Trajectory &trajectory)
  {
    trajectory_ = &trajectory;
  }
  bool RamsetePathFollower::isFinished() const
  {
    return finished_;
  }
  void RamsetePathFollower::reset()
  {
    finished_ = false;
    timer_.reset();
    chassis_.drive(0.0f, 0.0f, 0.0f);
  }
}