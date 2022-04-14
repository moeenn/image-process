#pragma once
#include <iostream>
#include <stdexcept>
#include <sstream>

class RGB {
private:
  static uint s_max_rgb;
  uint m_red;
  uint m_green;
  uint m_blue;

public:
  RGB(const uint red, const uint green, const uint blue);

  uint red() const;
  uint green() const;
  uint blue() const;
};