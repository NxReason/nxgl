#pragma once

#include "nxgl/math/Vec3.hpp"
#include "nxgl/Shader.h"
#include "nxgl/VAO.h"
#include "nxgl/VBO.h"
#include "nxgl/EBO.h"
#include "nxgl/Shape.h"

class Rectangle : public IShape {
private:
  Vec3 topleft;
  Vec3 bottomright;

  VBO vbo;
  EBO ebo;
  VAO vao;
public:
  Rectangle(Vec3 topleft, Vec3 bottomright);

  void draw() override;
};