#include "nxgl/VAO.h"
#include <glad/glad.h>

VAO::VAO() {
  glGenVertexArrays(1, &id);
}

void VAO::addBuffer(const VBO& vbo, const VertexLayout& layout) {
  bind();
  vbo.bind();
  const auto& elements = layout.getElements();
  unsigned int offset = 0;

  for (unsigned int i = 0; i < elements.size(); i++) {
    const auto& attr = elements[i];
    glEnableVertexAttribArray(i);
    glVertexAttribPointer(
      i,
      attr.count,
      attr.type,
      attr.normalized,
      layout.getStride(),
      (const void*)(uintptr_t)offset
    );
    offset += attr.count * VertexElement::getSizeOfType(attr.type);
  }
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