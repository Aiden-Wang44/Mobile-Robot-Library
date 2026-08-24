#pragma once
#include "mrl/Core/Chassis/Chassis.hpp"
#include "mrl/Core/MotorGroup.hpp"
namespace mrl
{
  class TankDrive : public Chassis
  {
  private:
    MotorGroup &left_;
    MotorGroup &right_;
    float wheelRadius_ = 0.0f;

  public:
    explicit TankDrive(MotorGroup &left, MotorGroup &right, float wheelRadius);
    void drive(float forward, float lateral, float angular) override;
    void driveVelocity(float forwardVelocity, float lateralVelocity, float angularVelocity) override;
    float getWheelRadius() const override;
  };

}