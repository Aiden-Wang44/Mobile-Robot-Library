#include "mrl/Core/MotorGroup.hpp"

#include <utility>
#include <stdexcept>
//std except is not used in the library due to some platforms not supporting exceptions during runtime
namespace mrl
{

  MotorGroup::MotorGroup(
      std::vector<std::reference_wrapper<Motor>> motors) : motors_(std::move(motors))
  {
    if (motors_.empty())
    {

      // throw std::invalid_argument("MotorGroup cannot be empty");
    }
  }
  void MotorGroup::setVoltage(float volts)
  {

    for (Motor &motor : motors_)
    {
      motor.setVoltage(volts);
    }
  }
  void MotorGroup::setVelocity(float velocity)
  {
    for (Motor &motor : motors_)
    {
      motor.setVelocity(velocity);
    }
  }
  float MotorGroup::getAveragePosition() const
  {
    float positions = 0.0f;
    for (const Motor &motor : motors_)
    {
      positions += motor.getPosition();
    }
    return positions / static_cast<float>(motors_.size());
  }
  float MotorGroup::getAverageVelocity() const
  {
    float velocities = 0.0f;
    for (const Motor &motor : motors_)
    {
      velocities += motor.getVelocity();
    }
    return velocities / static_cast<float>(motors_.size());
  }
  void MotorGroup::setBrake(BrakeMode mode)
  {
    for (Motor &motor : motors_)
    {
      motor.setBrake(mode);
    }
  }

}