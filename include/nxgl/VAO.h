#pragma once
#include <iostream>
#include <glad/glad.h>
#include "nxgl/VBO.h"
#include "nxgl/VertexLayout.hpp"

class VAO {
private:
  unsigned int id;
  GLuint attrPos = 0;
  GLintptr attrOffset = 0;
  GLsizei attrStride = 0;
public:
  VAO();

  void addBuffer(const VBO& vbo, const VertexLayout& layout);
  void bind();
  void unbind();
  void clear();
};