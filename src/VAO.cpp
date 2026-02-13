#include "nxgl/VAO.h"
#include <glad/glad.h>

VAO::VAO() {
  glGenVertexArrays(1, &id);
  glBindVertexArray(id);
}

void VAO::defineAttrib() {
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
}

void VAO::use() {
  glBindVertexArray(id);
}

void VAO::clear() {
  glDeleteVertexArrays(1, &id);
}