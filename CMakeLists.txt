cmake_minimum_required(VERSION 3.13)
project(NXGL)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GLFW_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw")
set(GLAD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/glad")
set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui")
set(STBI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/stbi")

set(IMGUI_SOURCES
  ${IMGUI_DIR}/imgui.cpp
  ${IMGUI_DIR}/imgui_draw.cpp
  ${IMGUI_DIR}/imgui_tables.cpp
  ${IMGUI_DIR}/imgui_widgets.cpp
  ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
  ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

add_executable(nxgl
  main.cpp
  "${GLAD_DIR}/src/glad.c"
  "${STBI_DIR}/stbi_image.cpp"
  ${IMGUI_SOURCES})

add_subdirectory(src)

target_include_directories(nxgl PRIVATE 
  include
  "${GLFW_DIR}/include"
  "${GLAD_DIR}/include"
  "${IMGUI_DIR}/"
  "${STBI_DIR}/"
)

target_link_libraries(nxgl PRIVATE
  "${GLFW_DIR}/src/libglfw3.a"
  opengl32
  gdi32
  user32
)

add_custom_command(TARGET nxgl POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  "${CMAKE_CURRENT_SOURCE_DIR}/assets"
  "$<TARGET_FILE_DIR:nxgl>/assets"
  COMMENT "Copying shaders to build dir"
  VERBATIM)