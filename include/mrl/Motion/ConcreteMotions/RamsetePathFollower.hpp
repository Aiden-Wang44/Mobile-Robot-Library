#pragma once
#include "mrl/Motion/MotionController.hpp"
#include "mrl/Localizers/Localizer.hpp"
#include "mrl/Core/Chassis/Chassis.hpp"
#include "mrl/Trajectory/Trajectory.hpp"
#include "mrl/Utilities/Timer/Timer.hpp"
namespace mrl
{
  struct RamseteParameters
  {
    float beta_ = 0.0f;
    float zeta_ = 0.0f;
    RamseteParameters() = default;
    RamseteParameters(float beta, float zeta) : beta_(beta), zeta_(zeta) {}
  };

  class RamsetePathFollower : public MotionController
  {
  private:
    Localizer &localizer_;
    Chassis &chassis_;
    const Trajectory *trajectory_;
    Timer &timer_;
    bool finished_ = false;
    RamseteParameters &ramseteParameters_;

  public:
    RamsetePathFollower(Localizer &localizer, Chassis &chassis, const Trajectory &trajectory, Timer &timer, RamseteParameters &ramseteParameters);
    void update() override;
    void setTarget(const Trajectory &trajectory);
    bool isFinished() const override;
    void reset() override;
  };
}