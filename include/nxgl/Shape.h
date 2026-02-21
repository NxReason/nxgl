#pragma once
#include "nxgl/Shader.h"

class IShape {
public:
  virtual void draw() = 0;
  virtual ~IShape() {}
};