#include "nxgl/EBO.h"
#include <glad/glad.h>

EBO::EBO() {
  glGenBuffers(1, &id);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

EBO::EBO(std::vector<unsigned int> indices) {
  glGenBuffers(1, &id);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
  load(indices);
}

void EBO::load(std::vector<unsigned int> indices) {
  unsigned long size = indices.size() * sizeof(unsigned int);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices.data(), GL_STATIC_DRAW);
}

void EBO::clear() {
  glDeleteBuffers(1, &id);
}