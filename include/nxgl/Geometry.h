#pragma once
#include <string>
#include <vector>

class Geometry {
private:
  std::vector<float> values;
public:
  Geometry(const std::string& fn);
  std::vector<float> getValues() const;
};
