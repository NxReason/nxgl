#include "nxgl/Texture.h"
#include <iostream>
#include <glad/glad.h>

Texture::Texture() {
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
  // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

  glGenTextures(1, &id);
}

void Texture::bind(unsigned int slot) {
  glActiveTexture(GL_TEXTURE0 + slot);
  glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::loadData(const ImageData& id) {
  int chan;
  switch (id.nrChannels) {
    case 3:
      chan = GL_RGB;
      break;
    case 4:
      chan = GL_RGBA;
      break;
    default:
      std::cout << "Invalid number of channels in the image (must be 3 or 4), received " << id.nrChannels << std::endl;
      break;
  }
  glTexImage2D(GL_TEXTURE_2D, 0, chan, id.width, id.height, 0, chan, GL_UNSIGNED_BYTE, id.data);
  glGenerateMipmap(GL_TEXTURE_2D);
}