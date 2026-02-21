#include "nxgl/Window.h"
#include <iostream>

void framebufferSizeCallback(GLFWwindow* window, int width, int height);

Window::Window(const char* appName) {
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window = glfwCreateWindow(800, 600, appName, nullptr, nullptr);
  if (!window) {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "Failed to init GLAD" << std::endl;
  }

  glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
}


GLFWwindow* Window::getWindow() const {
  return window;
}

bool Window::isRunning() const {
  return !glfwWindowShouldClose(window);
}

void Window::refresh() {
  glfwSwapBuffers(window);
  glfwPollEvents();
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

void Window::terminate() {
  glfwTerminate();
}