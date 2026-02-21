#pragma once

#include <string>
#include <unordered_map>
#include <glad/glad.h>

#include "nxgl/math/Vec3.hpp"
#include "nxgl/math/Mat4.hpp"

class ShaderProgram {
private:
  unsigned int id;
  std::unordered_map<std::string, int> uniformLocationCache;
public:
  ShaderProgram();
  ShaderProgram(unsigned int vs, unsigned int fs);
  ShaderProgram(const char* vertexFile, const char* fragFile);
  ShaderProgram(const std::string& vertexFile, const std::string& fragFile);
  ~ShaderProgram();

  void link(unsigned int vs, unsigned int fs);
  void bind() const;
  unsigned int getId() const;

  int getUniformLocation(const std::string& uName);
  void setFloat(const std::string& name, float value);
  void setInt(const std::string& name, int value);
  void setVec3(const std::string& name, Vec3 vec);
  void setMat4(const std::string& name, Mat4 mat);
};

class Shader {
private:
  unsigned int id;
public:
  Shader(const char* path, GLenum shaderType);
  ~Shader();

  unsigned int getId() const;
};