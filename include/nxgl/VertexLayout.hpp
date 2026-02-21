#pragma once
#include <vector>
#include <glad/glad.h>

struct VertexElement {
  unsigned int type;
  unsigned int count;
  unsigned char normalized;

  static unsigned int getSizeOfType(unsigned int type) {
    switch (type) {
      case GL_FLOAT:         return 4;
      case GL_UNSIGNED_INT:  return 4;
      case GL_UNSIGNED_BYTE: return 1;
      default:
        std::cout << "Invalid GL type: " << type << std::endl;
        return 0;
    }
  }
};

class VertexLayout {
private:
  std::vector<VertexElement> elements;
  unsigned int stride;

public:
  VertexLayout() : stride(0) {};

  template<typename T>
  void push(unsigned int count);

  inline const std::vector<VertexElement>& getElements() const { return elements; }
  inline unsigned int getStride() const { return stride; }
};

template<>
inline void VertexLayout::push<float>(unsigned int count) {
  elements.push_back({ GL_FLOAT, count, GL_FALSE });
  stride += count * VertexElement::getSizeOfType(GL_FLOAT);
}

template<>
inline void VertexLayout::push<unsigned int>(unsigned int count) {
  elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
  stride += count * VertexElement::getSizeOfType(GL_UNSIGNED_INT);
}

template<>
inline void VertexLayout::push<unsigned char>(unsigned int count) {
  elements.push_back({ GL_UNSIGNED_BYTE, count, GL_FALSE });
  stride += count * VertexElement::getSizeOfType(GL_UNSIGNED_BYTE);
}