#include <iostream>
#include <memory>

#include "nxgl/Window.h"
#include "nxgl/UI.h"

#include "nxgl/math/Vec3.hpp"

#include "nxgl/Renderer.h"
#include "nxgl/shapes/Triangle.hpp"
#include "nxgl/shapes/Rectangle.hpp"
#include "nxgl/shapes/Circle.hpp"

void processInput(GLFWwindow* window);

int main() {
  Window wnd("NXGL");

  // auto rect = std::make_unique<Rectangle>( Vec3{ 100.0f, 100.0f, 0.0f }, Vec3{ 600.0f, 600.0f, 0.0f } );
  auto rect = std::make_unique<Rectangle>( Vec3{ -1.0f, -1.0f, 0.0f }, Vec3{ 1.0f, 1.0f, 0.0f } );
  // auto triangle = std::make_unique<Triangle>(
  //   Vec3{ -0.5f, -0.5f },
  //   Vec3{  0.5f, -0.5f },
  //   Vec3{  0.0f,  0.5f } 
  // );
  auto triangle = std::make_unique<Triangle>(
    Vec3 { 100, 300 },
    Vec3 { 400, 300 },
    Vec3 { 250, 500 }
  );
  auto circle = std::make_unique<Circle>( Vec3{ 0.0f, 0.0f }, 0.5f );
  Renderer renderer;
  renderer.addShape(std::move(rect));
  // renderer.addShape(std::move(triangle));
  // renderer.addShape(std::move(circle));

  // IMGUI
  UI ui(wnd.getWindow());

  renderer.preset();

  while (wnd.isRunning()) {
    processInput(wnd.getWindow());

    renderer.render();

    wnd.refresh();
  }
  Window::terminate();
  return 0;
}

void processInput(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}
