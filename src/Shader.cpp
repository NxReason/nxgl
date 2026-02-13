#include "nxgl/Shader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Shader::Shader(const char* path, GLenum shaderType) {
  std::ifstream file(path);
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << path << std::endl;
    return;
  }
  std::stringstream buffer;
  buffer << file.rdbuf();
  std::string content = buffer.str(); 
  auto shaderCstr = content.c_str();

  id = glCreateShader(shaderType);
  glShaderSource(id, 1, &shaderCstr, nullptr);
  glCompileShader(id);

  file.close();
}

unsigned int Shader::getId() const {
  return id;
}

void Shader::clear() {
  glDeleteShader(id);
}