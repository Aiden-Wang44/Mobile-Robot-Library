#pragma once
namespace mrl
{
  class Controller
  {
  public:
    virtual ~Controller() = default;
    virtual void update(float current) = 0;
    virtual void setTarget(float target) = 0;
    virtual float getOutput() const = 0;
    virtual void reset() = 0;
    virtual float getError() const = 0;
    virtual bool targetArrived() const = 0;
  };
}