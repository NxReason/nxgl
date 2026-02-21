#pragma once
#include <vector>
#include "nxgl/math/Vec3.hpp"

class VBO {
private:
  unsigned int id;
public:
  VBO();
  VBO(std::vector<float> data);

  void load(std::vector<float> data);
  void load(float* data, unsigned int size);

  void bind() const;
  void clear();
};