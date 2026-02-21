#include "nxgl/Renderer.h"

#include <cmath>

#include "nxgl/Window.h"

#include "nxgl/ImageData.h"
#include "nxgl/Texture.h"
#include "nxgl/math/Mat4.hpp"
#include "nxgl/math/Vec3.hpp"
#include "nxgl/math/ops.hpp"

Renderer::Renderer() {
  Shader vs("assets/shaders/shader.vert", GL_VERTEX_SHADER);
  Shader fs("assets/shaders/shader.frag", GL_FRAGMENT_SHADER);
  shader.link(vs.getId(), fs.getId());
}

Renderer::Renderer(ShaderProgram& shader) : shader(shader) {}

void Renderer::addShape(std::unique_ptr<IShape> shape) {
  shapes.push_back(std::move(shape));
}

void Renderer::preset() {
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glEnable(GL_DEPTH_TEST);

  Vec3 color{ 1.0f, 0.1f, 1.0f};
  shader.bind();
  shader.setVec3("uColor", color);

  shader.setInt("uTexture", 0);
  ImageData id("assets/textures/awesomeface.png");
  Texture tex;
  tex.bind(0);
  tex.loadData(id);

  // Mat4 proj = Mat4::ortho(0.0f, 800.0f, 600.0f, 0.0f, -100.0f, 100.0f);
  Mat4 proj = Mat4::perspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);
  shader.setMat4("proj", proj);

  Mat4 model;
  shader.setMat4("model", model);
}

void Renderer::render() {
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  float time = (float)glfwGetTime();
  Mat4 tran = Mat4::translate({ 0.0f, 0.0f, -5.0f + (float)sin(time) });
  Mat4 rot = Mat4::rotate(time, { 0, 1, 0 });
  Mat4 scale = Mat4::scale(1.0f);
  Mat4 model = tran * rot * scale;

  shader.bind();
  shader.setMat4("model", model);
  for(auto& shape : shapes) {
    shape->draw();
  }
}