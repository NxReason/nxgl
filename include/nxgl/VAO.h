#pragma once

class VAO {
private:
  unsigned int id;
public:
  VAO();
  void defineAttrib();
  void use();
  void clear();
};