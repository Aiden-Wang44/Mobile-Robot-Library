#pragma once
#include <functional>
#include "mrl/Core/Motor.hpp"
#include <vector>
namespace mrl
{
  class MotorGroup
  {
  private:
    std::vector<std::reference_wrapper<Motor>> motors_;

  public:
    explicit MotorGroup(std::vector<std::reference_wrapper<Motor>> motors);
    void setVoltage(float volts);
    float getAveragePosition() const;
    float getAverageVelocity() const;
    void setBrake(BrakeMode mode);
  };
}