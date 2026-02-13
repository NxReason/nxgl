#pragma once
#include <GLFW/glfw3.h>

class UI {
public:
  UI(GLFWwindow* window);
  void render();
  void drawData();
  void clear();
};