#pragma once
#include <vector>

class VBO {
private:
  unsigned int id;
public:
  VBO();
  VBO(std::vector<float> data);
  void load(std::vector<float> data);
  void load(float* data, long size);
  void use();
  void clear();
};