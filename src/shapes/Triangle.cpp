#include "nxgl/shapes/Triangle.hpp"
#include <iostream>

#include "nxgl/VertexLayout.hpp"

Triangle::Triangle(Vec3 v1, Vec3 v2, Vec3 v3)
  : v1(v1), v2(v2), v3(v3) {
  float vertexData[] = {
    v1.x, v1.y, v1.z, 0.0f, 0.0f,
    v2.x, v2.y, v2.z, 1.0f, 0.0f,
    v3.x, v3.y, v3.z, 0.5f, 1.0f,
  };
  vbo.load(vertexData, 15);

  VertexLayout layout;
  layout.push<float>(3);
  layout.push<float>(2);
  vao.addBuffer(vbo, layout);
}

void Triangle::draw() {
  vao.bind();
  glDrawArrays(GL_TRIANGLES, 0, 3);
}