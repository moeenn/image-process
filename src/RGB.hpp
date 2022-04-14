#pragma once
#include <iostream>

class RGB {
private:
  uint m_red;
  uint m_green;
  uint m_blue;

public:
  RGB(const uint red, const uint green, const uint blue);

  uint red() const;
  uint green() const;
  uint blue() const;
};