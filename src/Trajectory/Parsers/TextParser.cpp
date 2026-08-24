#include "mrl/Trajectory/Parsers/TextParser.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
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
      time = std::stof(value);
      std::getline(lineStream, value, ',');
      x = std::stof(value);
      std::getline(lineStream, value, ',');
      y = std::stof(value);
      std::getline(lineStream, value, ',');
      heading = std::stof(value);
      std::getline(lineStream, value, ',');
      linearVelocity = std::stof(value);
      std::getline(lineStream, value, ',');
      angularVelocity = std::stof(value);
      points.emplace_back(time, Pose(x, y, heading), linearVelocity, angularVelocity);
    }
    return Trajectory(points);
  }
}