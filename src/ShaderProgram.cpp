#include "nxgl/Shader.h"

ShaderProgram::ShaderProgram(unsigned int vs, unsigned int fs) {
  id = glCreateProgram();
  glAttachShader(id, vs);
  glAttachShader(id, fs);
  glLinkProgram(id);
}

void ShaderProgram::use() const {
  glUseProgram(id);
}

unsigned int ShaderProgram::getId() const {
  return id;
}

void ShaderProgram::clear() {
  glDeleteProgram(id);
}