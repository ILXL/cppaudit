#include <iostream>

#include "cpputils/graphics/image.h"

int main() {
  graphics::Image image(100, 100);
  image.DrawCircle(50, 50, 40, 255, 0, 100);
  image.SaveImageBmp("example.bmp");
  std::cout << "Image save to example.bmp" << std::endl;
  return 0;
}
