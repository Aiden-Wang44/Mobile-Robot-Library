#pragma once
#include "mrl/Trajectory/Parsers/TrajectoryParser.hpp"
namespace mrl
{
  class TextParser : public TrajectoryParser
  {
  public:
    TextParser();
    Trajectory parse(const char *filePath) const override;
  };
}