cmake_minimum_required(VERSION 3.10)
project(VSGL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GLFW_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glfw")
set(GLAD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glad")


add_executable(vsgl
  main.cpp
  "${GLAD_DIR}/src/glad.c")

target_include_directories(vsgl PRIVATE 
  "${GLFW_DIR}/include"
  "${GLAD_DIR}/include"
)

target_link_libraries(vsgl PRIVATE
  "${GLFW_DIR}/src/libglfw3.a"
  opengl32
  gdi32
  user32
)