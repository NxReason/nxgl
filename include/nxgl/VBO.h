#pragma once

class VBO {
private:
  unsigned int id;
public:
  VBO();
  void loadData(float* data, long size);
  void use();
  void clear();
};