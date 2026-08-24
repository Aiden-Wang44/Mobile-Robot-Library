#include "mrl/Trajectory/Parsers/TextParser.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
namespace mrl
{
  Trajectory TextParser::parse(const char *filePath) const
  {
    std::ifstream file(filePath);
    std::vector<TrajectoryPoint> points;
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
      if (line.empty())
      {
        continue;
      }
      std::stringstream lineStream(line);
      std::string value;
      float time;
      float x;
      float y;
      float heading;
      float linearVelocity;
      float angularVelocity;
      std::getline(lineStream, value, ',');
      time = strtof(value.c_str(), nullptr);
      std::getline(lineStream, value, ',');
      x = strtof(value.c_str(), nullptr);
      std::getline(lineStream, value, ',');
      y = strtof(value.c_str(), nullptr);
      std::getline(lineStream, value, ',');
      heading = strtof(value.c_str(), nullptr);
      std::getline(lineStream, value, ',');
      linearVelocity = strtof(value.c_str(), nullptr);
      std::getline(lineStream, value, ',');
      angularVelocity = strtof(value.c_str(), nullptr);
      points.emplace_back(time, Pose(x, y, heading), linearVelocity, angularVelocity);
    }
    return Trajectory(points);
  }
}