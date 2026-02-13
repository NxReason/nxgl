#pragma once

#include <glad/glad.h>

class ShaderProgram {
private:
  unsigned int id;
public:
  ShaderProgram(unsigned int vs, unsigned int fs);
  void use() const;
  unsigned int getId() const;
  void clear();
};

class Shader {
private:
  unsigned int id;
public:
  Shader(const char* path, GLenum shaderType);
  unsigned int getId() const;
  void clear();
};