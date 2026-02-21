#pragma once
#include "nxgl/math/Vec3.hpp"
#include "nxgl/Shape.h"
#include "nxgl/VAO.h"
#include "nxgl/VBO.h"
#include "nxgl/EBO.h"

class Circle : public IShape {
private:
  VAO vao;
  VBO vbo;
  EBO ebo;
  unsigned int indicesCount;
public:
  Circle(Vec3 center, float radius, int segments = 32);
  void draw() override;
};