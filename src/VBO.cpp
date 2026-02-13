#include "nxgl/VBO.h"
#include <glad/glad.h>

VBO::VBO() {
  glGenBuffers(1, &id);
  glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::loadData(float* data, long size) {
  glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void VBO::use() {
  glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::clear() {
  glDeleteBuffers(1, &id);
}