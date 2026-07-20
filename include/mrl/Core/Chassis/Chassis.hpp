#pragma once
namespace mrl
{
  class Chassis
  {
  public:
    virtual ~Chassis() = default;
    virtual void drive(float forward, float lateral, float angular) = 0;
  };

}