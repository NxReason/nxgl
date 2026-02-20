#include "nxgl/VAO.h"
#include <glad/glad.h>

VAO::VAO() {
  glGenVertexArrays(1, &id);
  glBindVertexArray(id);
}

void VAO::bind() {
  glBindVertexArray(id);
}

void VAO::unbind() {
  glBindVertexArray(0);
}

void VAO::clear() {
  glDeleteVertexArrays(1, &id);
}