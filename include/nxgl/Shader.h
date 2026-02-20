#pragma once

#include <string>
#include <glad/glad.h>

class ShaderProgram {
private:
  unsigned int id;
public:
  ShaderProgram();
  ShaderProgram(unsigned int vs, unsigned int fs);
  void link(unsigned int vs, unsigned int fs);
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