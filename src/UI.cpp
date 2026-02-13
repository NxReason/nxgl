#include "nxgl/UI.h"

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

static float color[3] = { 0.1f, 0.1f, 0.1f };
static int counter = 0;

UI::UI(GLFWwindow* window) {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;

  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 330");

  ImGui::StyleColorsDark();
}

void UI::render() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  ImGui::Begin("Settings");
  ImGui::Text("Adjust the background color");
  ImGui::ColorEdit3("Clear color", color);

  if (ImGui::Button("Click me")) {
    counter++;
  }
  ImGui::SameLine();
  ImGui::Text("Count: %d", counter);

  ImGui::End();
  ImGui::Render();
}

void UI::drawData() {
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UI::clear() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}