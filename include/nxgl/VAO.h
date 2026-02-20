#pragma once
#include <iostream>
#include <glad/glad.h>

class VAO {
private:
  unsigned int id;
  GLuint attrPos = 0;
  GLintptr attrOffset = 0;
  GLsizei attrStride = 0;
public:
  VAO();
  void setStride(GLsizei stride) { attrStride = stride; }
  template<typename T>
  void attr(int size);
  void bind();
  void unbind();
  void clear();
};

template<>
inline void VAO::attr<float>(GLint size) {
  std::cout << size << ", " << attrPos << ", " << attrOffset << ", " << attrStride << std::endl;
  glVertexAttribPointer(attrPos, size, GL_FLOAT, GL_FALSE, attrStride, (void*)(attrOffset * sizeof(float)));
  glEnableVertexAttribArray(attrPos);

  attrPos += 1;
  attrOffset += (GLintptr)size;
}