#pragma once
#include "nxgl/ImageData.h"

class Texture {
private:
  unsigned int id;
public:
  Texture();

  void bind(unsigned int slot = 0);
  void loadData(const ImageData& id);
};
