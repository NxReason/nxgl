#pragma once
#include <string>
#include <unordered_map>
#include "nxgl/Shader.h"
#include "nxgl/VAO.h"
#include "nxgl/VBO.h"
#include "nxgl/EBO.h"

typedef std::unordered_map<std::string, std::string> ShaderPaths;

class Square {
private:
  VAO vao;
  VBO vbo;
  EBO ebo;
public:
  ShaderProgram program;
  Square(const std::string& path, ShaderPaths shaders = {});
  ~Square();
  void draw();
};
