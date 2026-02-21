#include "nxgl/Shader.h"
#include <iostream>

ShaderProgram::ShaderProgram() {
  id = glCreateProgram();
}

ShaderProgram::ShaderProgram(unsigned int vs, unsigned int fs) {
  id = glCreateProgram();
  link(vs, fs);
}

ShaderProgram::ShaderProgram(const char* vertexFile, const char* fragFile) {
  Shader vert { vertexFile, GL_VERTEX_SHADER };
  Shader frag { fragFile, GL_FRAGMENT_SHADER };

  id = glCreateProgram();
  link(vert.getId(), frag.getId());
}
ShaderProgram::ShaderProgram(const std::string& vertexFile, const std::string& fragFile)
  : ShaderProgram(vertexFile.c_str(), fragFile.c_str()) { }

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

void ShaderProgram::bind() const {
  glUseProgram(id);
}

unsigned int ShaderProgram::getId() const {
  return id;
}

int ShaderProgram::getUniformLocation(const std::string& name) {
  if (uniformLocationCache.find(name) != uniformLocationCache.end())
    return uniformLocationCache[name];

  int location = glGetUniformLocation(id, name.c_str());
  if (location == -1) {
    std::cerr << "Failed to get uniform location (" << name <<  ")" << std::endl;
  }

  uniformLocationCache[name] = location;
  return location;
}

void ShaderProgram::setFloat(const std::string& name, float value) {
  bind();
  int location = getUniformLocation(name);
  glUniform1f(location, value);
}

void ShaderProgram::setInt(const std::string &name, int value) {
  bind();
  int location = getUniformLocation(name);
  glUniform1i(location, value);
}

void ShaderProgram::setVec3(const std::string& name, Vec3 vec) {
  bind();
  int location = getUniformLocation(name);
  glUniform3f(location, vec.x, vec.y, vec.z);
}

void ShaderProgram::setMat4(const std::string& name, Mat4 mat) {
  bind();
  int location = getUniformLocation(name);
  glUniformMatrix4fv(location, 1, GL_FALSE, &mat.elements[0]);
}

ShaderProgram::~ShaderProgram() {
  glDeleteProgram(id);
}