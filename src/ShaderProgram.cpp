#include "nxgl/Shader.h"
#include <iostream>

ShaderProgram::ShaderProgram() {
  id = glCreateProgram();
}

ShaderProgram::ShaderProgram(unsigned int vs, unsigned int fs) {
  id = glCreateProgram();
  link(vs, fs);
}

void ShaderProgram::link(unsigned int vs, unsigned int fs) {
  glAttachShader(id, vs);
  glAttachShader(id, fs);
  glLinkProgram(id);
  int success;
  char infoLog[512];
  glGetProgramiv(id, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(id, 512, nullptr, infoLog);
    std::cerr << "Error linking shader program: " << infoLog << std::endl;
  }
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