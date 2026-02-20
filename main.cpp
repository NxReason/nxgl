#include <iostream>

#include "nxgl/Window.h"
#include "nxgl/Shader.h"
#include "nxgl/UI.h"
#include "nxgl/Geometry.h"
#include "nxgl/VAO.h"
#include "nxgl/VBO.h"
#include "nxgl/EBO.h"

void processInput(GLFWwindow* window);

std::pair<ShaderProgram, VAO> drawTriangle();
std::pair<ShaderProgram, VAO> makeRainbowTriangle();

int main() {
  Window wnd("NXGL");

  auto triangle = makeRainbowTriangle();
  // IMGUI
  UI ui(wnd.getWindow());

  while (wnd.isRunning()) {
    // render
    processInput(wnd.getWindow());
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    triangle.first.use();
    triangle.second.bind();
    glDrawArrays(GL_TRIANGLES, 0, 6);
    triangle.second.unbind();

    wnd.refresh();
  }
  glfwTerminate();
  return 0;
}

void processInput(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

std::pair<ShaderProgram, VAO> drawTriangle() {
  Geometry triangleGeo("triangle.geo");
  VAO vao;
  VBO vbo{ triangleGeo.getValues() };
  Shader vertex{"assets/shaders/shader.vert", GL_VERTEX_SHADER};
  Shader frag{"assets/shaders/shader.frag", GL_FRAGMENT_SHADER};
  ShaderProgram program { vertex.getId(), frag.getId() };
  vao.setStride(3 * sizeof(float));
  vao.attr<float>(3);

  return std::pair{program, vao};
}

std::pair<ShaderProgram, VAO> makeRainbowTriangle() {
  Geometry triangleGeo("rainbowtriangle.geo");
  VAO vao;
  VBO vbo{ triangleGeo.getValues() };
  Shader vertex{"assets/shaders/poscol.vert", GL_VERTEX_SHADER};
  Shader frag{"assets/shaders/poscol.frag", GL_FRAGMENT_SHADER};
  ShaderProgram program { vertex.getId(), frag.getId() };
  program.use();
  vao.setStride(6 * sizeof(float));
  vao.attr<float>(3);
  vao.attr<float>(3);

  return std::pair{program, vao};
}