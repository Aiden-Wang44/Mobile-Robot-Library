#pragma once
namespace mrl
{
  class Rotation
  {
  public:
    virtual ~Rotation() = default;
    virtual float getPosition() const = 0;
    virtual float getVelocity() const = 0;
    virtual void resetPosition() = 0;
    virtual void setPosition(float position) = 0;
    virtual void setReversed(bool reversed) = 0;
  };
}