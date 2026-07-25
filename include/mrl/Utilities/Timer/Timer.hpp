#pragma once
namespace mrl
{
  class Timer
  {
  public:
    virtual ~Timer() = default;
    virtual float DeltaTime() const = 0;
    virtual void reset() = 0;
    virtual float getTime() const = 0;
  };
}