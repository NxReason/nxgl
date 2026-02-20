#pragma once
#include <vector>

class EBO {
private:
  unsigned int id;
public:
  EBO();
  EBO(std::vector<unsigned int> indices);
  void load(std::vector<unsigned int> indices);
  void clear();
};