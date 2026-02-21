#include "nxgl/shapes/Rectangle.hpp"

Rectangle::Rectangle(Vec3 o, Vec3 d) {
  vao.bind();
  float vertexData[] = {
    // pos          // tex
    o.x, o.y, 0.0f, 0.0f, 0.0f,
    o.x, d.y, 0.0f, 0.0f, 1.0f,
    d.x, o.y, 0.0f, 1.0f, 0.0f,
    d.x, d.y, 0.0f, 1.0f, 1.0f,
  };
  vbo.load(vertexData, 20);

  unsigned int indices[] = {
    0, 1, 3,
    3, 2, 0
  };
  ebo.load(indices, 6);

  VertexLayout layout;
  layout.push<float>(3);
  layout.push<float>(2);
  vao.addBuffer(vbo, layout);

  vao.unbind();
}

void Rectangle::draw() {
  vao.bind();
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}