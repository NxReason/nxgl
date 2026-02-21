#include "nxgl/Renderer.h"

#include "nxgl/ImageData.h"
#include "nxgl/Texture.h"

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

  Vec3 color{ 1.0f, 0.1f, 1.0f};
  shader.bind();
  shader.setVec3("uColor", color);
  shader.setFloat("uOffsetX", 0.0f);

  shader.setInt("uTexture", 0);
  ImageData id("assets/textures/awesomeface.png");
  Texture tex;
  tex.bind(0);
  tex.loadData(id);
}

void Renderer::render() {
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  shader.bind();
  for(auto& shape : shapes) {
    shape->draw();
  }
}