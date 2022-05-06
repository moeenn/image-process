#include "./filters.hpp"

uint filters::normalize(const uint &c) {
  if (c < 0) return 0;
  if (c > 255) return 255;

  return c;
}

void filters::grayscale(uint &r, uint &g, uint &b) {
  const uint avg = (r + g + b) / 3;
  r = g = b = avg;
}

void filters::darken(const float &factor, uint &r, uint &g, uint &b) {
  const uint red = r * factor,
        green = g * factor,
        blue = b * factor; 

  r = normalize(red);
  g = normalize(green);
  b = normalize(blue);
}