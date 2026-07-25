#pragma once
namespace mrl
{
  class MotionController
  {
  public:
    virtual ~MotionController() = default;
    virtual void update() = 0;
    virtual void setTarget(float target);
    virtual bool isFinished() const = 0;
    virtual void reset() = 0;
  };
}