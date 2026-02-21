#include <iostream>
#include <memory>

#include "nxgl/Window.h"
#include "nxgl/UI.h"

#include "nxgl/math/Vec3.hpp"
#include "nxgl/math/ops.hpp"

#include "nxgl/Renderer.h"
#include "nxgl/shapes/Triangle.hpp"
#include "nxgl/shapes/Rectangle.hpp"
#include "nxgl/shapes/Circle.hpp"

void processInput(GLFWwindow* window);

int main() {
  Window wnd("NXGL");

  auto rect = std::make_unique<Rectangle>( Vec3{ -0.5f, 0.5f }, Vec3{ 0.2f, -0.2f } );
  auto triangle = std::make_unique<Triangle>(
    Vec3{ -0.5f, -0.5f },
    Vec3{ 0.0f, -0.5f },
    Vec3{ -0.25f, 0.0f} 
  );
  auto circle = std::make_unique<Circle>( Vec3{ 0.0f, 0.0f }, 0.5f );
  Renderer renderer;
  // renderer.addShape(std::move(rect));
  // renderer.addShape(std::move(triangle));
  renderer.addShape(std::move(circle));

  // IMGUI
  UI ui(wnd.getWindow());

  renderer.preset();

  const Vec3 v { 3.0, 4.0 };
  std::cout << math::length(v) << std::endl;

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
