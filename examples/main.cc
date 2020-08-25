#include <iostream>
#include <string>
#include "cpputils/graphics/image.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  // Gets a filename from the user.
  string filename;
  cout << "Enter a filename for the resulting image: ";
  cin >> filename;
  const int size = 200;
  graphics::Image image(size, size);

  const int red = 0;
  const int green = 0;
  const int blue = 255;
  const int min_radius = 1;
  const int max_radius = size / 2;

  // Get a radius from the user.
  int radius;
  cout << "Please input the radius of your circle: ";
  cin >> radius;
  if (radius < min_radius || radius > max_radius) {
    cout << "The radius must be between 1 and 100.";
    return 1;
  }
  image.DrawCircle(size / 2, size / 2, radius, red, green, blue);

  // Saves the image with the specified filename.
  cout << "Your image was saved to " << filename << endl;
  image.SaveImageBmp(filename);
  return 0;
}
