#include "nxgl/shapes/Circle.hpp"
#include <cmath>
#include <iostream>

Circle::Circle(Vec3 center, float radius, int segments) {
  vao.bind();

  std::vector<float> positions;
  std::vector<unsigned int> indices;
  positions.push_back(center.x);
  positions.push_back(center.y);
  positions.push_back(center.z);
  for (int i = 0; i < segments; i++) {
    float theta = 2.0f * 3.14159f * float(i) / float(segments);
    positions.push_back(center.x + radius * cos(theta));
    positions.push_back(center.y + radius * sin(theta));
    positions.push_back(0.0f);
  }

  vbo.load(positions.data(), positions.size());

  for (int i = 1; i <= segments; i++) {
    indices.push_back(0);
    indices.push_back(i);
    indices.push_back(i + 1);
  }
  indicesCount = indices.size();
  indices[indices.size() - 1] = 1;
  ebo.load(indices.data(), indices.size());

  VertexLayout layout;
  layout.push<float>(3);
  vao.addBuffer(vbo, layout);

  vao.unbind();
}

void Circle::draw() {
  vao.bind();
  glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, nullptr);
}