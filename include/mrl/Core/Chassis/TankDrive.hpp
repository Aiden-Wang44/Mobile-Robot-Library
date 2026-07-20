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

  public:
    explicit TankDrive(MotorGroup &left, MotorGroup &right);
    void drive(float forward, float lateral, float angular) override;
  };

}