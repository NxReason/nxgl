target_sources(nxgl PRIVATE
  Window.cpp
  UI.cpp
  Geometry.cpp
  ImageData.cpp
  Renderer.cpp

  wrappers/Shader.cpp
  wrappers/ShaderProgram.cpp
  wrappers/VAO.cpp
  wrappers/VBO.cpp
  wrappers/EBO.cpp
  wrappers/Texture.cpp

  shapes/Triangle.cpp
  shapes/Rectangle.cpp
  shapes/Circle.cpp
)
