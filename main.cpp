#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

const char* vertexShaderSource = "#version 330 core\n"
  "layout (location = 0) in vec3 aPos;\n"
  "uniform float xOffset;\n"
  "uniform float yOffset;\n"
  "void main()\n"
  "{\n"
  "   gl_Position = vec4(aPos.x + xOffset, aPos.y + yOffset, aPos.z, 1.0);\n"
  "}\0";

// Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
  "out vec4 FragColor;\n"
  "void main()\n"
  "{\n"
  "   FragColor = vec4(0.4f, 0.25f, 0.65f, 1.0f);\n" // Orange color
  "}\n\0";

float xOffset = 0.0f;
float yOffset = 0.0f;
void processInput(GLFWwindow* window);

int main() {
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW + Cmake + G++", nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  // GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to init GLAD" << std::endl;
    return -1;
  }

  // build and compile shaders
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
  glCompileShader(vertexShader);

  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
  glCompileShader(fragmentShader);

  unsigned int shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  // vertex data
  float vertices[] = {
    -0.5f, -0.5f, 0.0f, // left
     0.5f, -0.5f, 0.0f, // right
     0.0f,  0.5f, 0.0f, // top
  };
  
  unsigned int VBO, VAO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  while (!glfwWindowShouldClose(window)) {
    processInput(window);

    // render
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);    
    
    // triangle
    glUseProgram(shaderProgram);

    int xLoc = glGetUniformLocation(shaderProgram, "xOffset");
    int yLoc = glGetUniformLocation(shaderProgram, "yOffset");
    glUniform1f(xLoc, xOffset);
    glUniform1f(yLoc, yOffset);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteProgram(shaderProgram);

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