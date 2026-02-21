#pragma once
#include <vector>

class EBO {
private:
  unsigned int id;
public:
  EBO();
  EBO(std::vector<unsigned int> indices);
  EBO(unsigned int* indices, unsigned int size);

  void load(std::vector<unsigned int> indices);
  void load(unsigned int* indices, unsigned int size);
  void bind();
  void unbind();
  void clear();
};