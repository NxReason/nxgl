#include "nxgl/Shader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const std::string PATH_PREFIX = "assets/shaders/";

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

  int success;
  char infoLog[512];
  glGetShaderiv(id, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(id, 512, nullptr, infoLog);
    std::cerr << "Error compiling shader: " << infoLog << std::endl;
  }

  file.close();
}

unsigned int Shader::getId() const {
  return id;
}

Shader::~Shader() {
  glDeleteShader(id);
}