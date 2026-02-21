#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
private:
  GLFWwindow* window;
public:
  static void terminate();
  Window(const char* appName = "App");
  GLFWwindow* getWindow() const;
  bool isRunning() const;
  void refresh();
};