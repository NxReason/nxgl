#pragma once
#include <string>

class ImageData {
public:
  int width;
  int height;
  int nrChannels;
  unsigned char* data;

  ImageData();
  ImageData(const std::string& filename);

  void load(const std::string& filename);

  ~ImageData();
};