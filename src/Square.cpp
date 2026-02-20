#include "nxgl/Square.h"
#include "nxgl/Geometry.h"
#include "nxgl/VBO.h"
#include "nxgl/EBO.h"

const std::string DEF_VERTEX_SHADER = "assets/shaders/shader.vert";
const std::string DEF_FRAGMENT_SHADER = "assets/shaders/shader.frag";

Square::Square(const std::string& path, ShaderPaths shaders) {
  Geometry geo(path);

  if (!shaders.contains("vertex")) shaders["vertex"] = DEF_VERTEX_SHADER;
  if (!shaders.contains("fragment")) shaders["fragment"] = DEF_FRAGMENT_SHADER;

  Shader vs(shaders.at("vertex").c_str(), GL_VERTEX_SHADER);
  Shader fs(shaders.at("fragment").c_str(), GL_FRAGMENT_SHADER);
  program.link(vs.getId(), fs.getId());
  vs.clear();
  fs.clear();

  std::vector<unsigned int> indices { 0, 1, 3, 1, 2, 3 };

  vbo.load(geo.getValues());
  ebo.load(indices);

  vao.defineAttrib();
}

Square::~Square() {
  vbo.clear();
  ebo.clear();
  vao.clear();
  program.clear();
}

void Square::draw() {
    vao.bind();
    program.use();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}