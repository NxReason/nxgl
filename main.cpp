#include <iostream>

#include "nxgl/Window.h"
#include "nxgl/Shader.h"
#include "nxgl/UI.h"
#include "nxgl/Geometry.h"
#include "nxgl/VAO.h"
#include "nxgl/VBO.h"

float xOffset = 0.0f;
float yOffset = 0.0f;
void processInput(GLFWwindow* window);

int main() {
  Window wnd("NXGL");

  // build and compile shaders
  Shader vs("assets/shaders/shader.vert", GL_VERTEX_SHADER);
  Shader fs("assets/shaders/shader.frag", GL_FRAGMENT_SHADER);
  ShaderProgram program(vs.getId(), fs.getId());
  vs.clear();
  fs.clear();

  // vertex data
  Geometry geo("triangle.geo");
  VAO vao;
  VBO vbo;

  auto size = geo.getValues().size() * sizeof(float);
  vbo.loadData(geo.getValues().data(), size);

  vao.defineAttrib();

  // IMGUI
  UI ui(wnd.getWindow());

  while (wnd.isRunning()) {
    processInput(wnd.getWindow());

    ui.render();

    // render
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    // triangle
    program.use();

    int xLoc = glGetUniformLocation(program.getId(), "xOffset");
    int yLoc = glGetUniformLocation(program.getId(), "yOffset");
    glUniform1f(xLoc, xOffset);
    glUniform1f(yLoc, yOffset);

    vao.use();
    glDrawArrays(GL_TRIANGLES, 0, 6);

    ui.drawData();
    wnd.refresh();
  }

  ui.clear();
  vao.clear();
  vbo.clear();
  program.clear();

  glfwTerminate();
  return 0;
}

void processInput(GLFWwindow* window) {
  float speed = 0.01f;

  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);

  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    xOffset -= speed;

  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    xOffset += speed;

  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    yOffset += speed;

  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    yOffset -= speed;
}