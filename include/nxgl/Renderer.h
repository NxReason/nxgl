#pragma once
#include <vector>
#include <memory>

#include "nxgl/Shader.h"
#include "nxgl/Shape.h"

class Renderer {
private:
  std::vector<std::unique_ptr<IShape>> shapes;
  ShaderProgram shader;
public:
  Renderer();
  Renderer(ShaderProgram& shader);

  void addShape(std::unique_ptr<IShape> shape);
  void preset();
  void render();
};