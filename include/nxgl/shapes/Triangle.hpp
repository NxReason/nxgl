#pragma once
#include "nxgl/math/Vec3.hpp"
#include "nxgl/VAO.h"
#include "nxgl/VBO.h"
#include "nxgl/Shader.h"
#include "nxgl/Shape.h"

class Triangle : public IShape {
private:
  Vec3 v1;
  Vec3 v2;
  Vec3 v3;

  VAO vao;
  VBO vbo;
public:
  Triangle(Vec3 v1, Vec3 v2, Vec3 v3);

  void draw() override;
};