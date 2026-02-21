#include "nxgl/EBO.h"
#include <glad/glad.h>

EBO::EBO() {
  glGenBuffers(1, &id);
}

EBO::EBO(std::vector<unsigned int> indices) {
  glGenBuffers(1, &id);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
  load(indices);
}

EBO::EBO(unsigned int* indices, unsigned int size) {
  glGenBuffers(1, &id);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
  load(indices, size);
}

void EBO::load(std::vector<unsigned int> indices) {
  bind();
  unsigned long size = indices.size() * sizeof(unsigned int);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices.data(), GL_STATIC_DRAW);
}

void EBO::load(unsigned int* indices, unsigned int size) {
  bind();
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(unsigned int), indices, GL_STATIC_DRAW);
}

void EBO::bind() {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}
void EBO::unbind() {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::clear() {
  glDeleteBuffers(1, &id);
}