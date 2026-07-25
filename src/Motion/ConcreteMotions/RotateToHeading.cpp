#include "mrl/Motion/ConcreteMotions/RotateToHeading.hpp"

namespace mrl
{
  RotateToHeading::RotateToHeading(Controller &controller, Localizer &localizer, Chassis &chassis, RotationLimits &rotationLimits) : controller_(controller), localizer_(localizer), chassis_(chassis), rotationLimits_(rotationLimits)
  {
  }
  void RotateToHeading::update()
  {
    Pose p = localizer_.getPose();
    controller_.update(p.heading);
    float output = controller_.getOutput();
    output = clamp(output, rotationLimits_.maxPower_, rotationLimits_.minPower_);
    chassis_.drive(0.0f, 0.0f, output);
  }
  void RotateToHeading::setTarget(float target)
  {
    controller_.reset();
    controller_.setTarget(target);
  }
  bool RotateToHeading::isFinished() const
  {
    return controller_.targetArrived();
  }
  void RotateToHeading::reset()
  {
    controller_.reset();
    chassis_.drive(0.0f, 0.0f, 0.0f);
  }
}