#include "nxgl/ImageData.h"
#include <iostream>

#include "stbi_image.h"

ImageData::ImageData() {}

ImageData::ImageData(const std::string& filename) {
  load(filename);
}

void ImageData::load(const std::string& filename) {
  stbi_set_flip_vertically_on_load(true);
  data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 0);
  if (!data) {
    std::cout << "Failed to load texture: " << filename << std::endl;
  }
}

ImageData::~ImageData() {
  stbi_image_free(data);
}