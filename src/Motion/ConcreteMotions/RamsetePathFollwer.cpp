#include "mrl/Motion/ConcreteMotions/RamsetePathFollower.hpp"
#include "mrl/Math/Angles.hpp"
//Ramsete equations differ from standard textbook control equations
//due to the library conention being local positive y-axis being forward
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

    float localErrorY =
        -globalErrorX * sin(p.heading) +
        globalErrorY * cos(p.heading);

    float localErrorX =
        globalErrorX * cos(p.heading) +
        globalErrorY * sin(p.heading);

    float localErrorHeading =
        normalizeAngle(target.pose_.heading - p.heading);
    float vd = target.linearVelocity_;
    float wd = target.angularVelocity_;
    float k =
        2.0f * ramseteParameters_.zeta_ * sqrt(wd * wd + ramseteParameters_.beta_ * vd * vd);

    float v =
        vd * cos(localErrorHeading) + k * localErrorY;

    float w =
        wd + k * localErrorHeading - ramseteParameters_.beta_ * vd * sinc(localErrorHeading) * localErrorX;
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