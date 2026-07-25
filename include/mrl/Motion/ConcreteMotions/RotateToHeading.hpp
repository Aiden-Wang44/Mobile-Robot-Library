#pragma once
#include "mrl/Localizers/Localizer.hpp"
#include "mrl/Motion/MotionController.hpp"
#include "mrl/Controllers/PID/PID.hpp"
#include "mrl/Core/Chassis/Chassis.hpp"
#include "mrl/Math/Angles.hpp"
namespace mrl
{
  struct RotationLimits
  {
    float maxPower_ = 0.0f;
    float minPower_ = 0.0f;
  };
  class RotateToHeading : public MotionController
  {
  private:
    Controller &controller_;
    Localizer &localizer_;
    Chassis &chassis_;
    RotationLimits &rotationLimits_;

  public:
    RotateToHeading(Controller &controller, Localizer &localizer, Chassis &chassis, RotationLimits &rotationlimits);
    void update() override;
    void setTarget(float target) override;
    bool isFinished() const override;
    void reset() override;
  };
}