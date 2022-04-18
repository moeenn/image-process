#include "./Filters.hpp"

void Filters::grayscale(RGB& rgb) {
  const uint red = rgb.red(), green = rgb.green(), blue = rgb.blue();
  const uint avg = (red + green + blue) / 3;

  rgb = RGB{avg, avg, avg};
}