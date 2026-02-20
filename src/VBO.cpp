#include "nxgl/VBO.h"
#include <glad/glad.h>

VBO::VBO() {
  glGenBuffers(1, &id);
  glBindBuffer(GL_ARRAY_BUFFER, id);
}

VBO::VBO(std::vector<float> data) {
  glGenBuffers(1, &id);
  glBindBuffer(GL_ARRAY_BUFFER, id);
  load(data);
}

void VBO::load(std::vector<float> data) {
  auto size = data.size() * sizeof(float);
  glBufferData(GL_ARRAY_BUFFER, size, data.data(), GL_STATIC_DRAW);
}

void VBO::load(float* data, long size) {
  glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void VBO::use() {
  glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::clear() {
  glDeleteBuffers(1, &id);
}