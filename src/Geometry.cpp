#include "nxgl/Geometry.h"
#include <iostream>
#include <fstream>

Geometry::Geometry(const std::string& fn) {
  std::ifstream file("assets/geometry/" + fn);
  if (!file.is_open()) {
    std::cerr << "Can't open geometry file " << fn << std::endl;
  }

  std::string word;
  while (file >> word) {
    try {
      float value = std::stof(word);
      values.push_back(value);
    }
    catch (const std::invalid_argument& e) {
      std::cerr << "invalid float value: " << word << std::endl;
    }
    catch (const std::out_of_range& e) {
      std::cerr << "value is too big to convert: " << word << std::endl;
    }
    catch (const std::exception& e) {
      std::cerr << "unhandled exception in geometry conversion" << e.what() << std::endl;
    }
  }

  file.close();
}


std::vector<float> Geometry::getValues() const {
  return values;
}