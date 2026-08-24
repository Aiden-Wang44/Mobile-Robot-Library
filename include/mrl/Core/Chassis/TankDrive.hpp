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
    float wheelDiameter_ = 0.0f;
    float trackWidth_ = 0.0f;

  public:
    explicit TankDrive(MotorGroup &left, MotorGroup &right, float wheelDiameter, float trackWidth);
    void drive(float forward, float lateral, float angular) override;
    void driveVelocity(float forwardVelocity, float lateralVelocity, float angularVelocity) override;
    };

}