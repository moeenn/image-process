#include "./RGB.hpp"

RGB::RGB(const uint red, const uint green, const uint blue)
      : m_red(red), m_green(green), m_blue(blue) {}

uint RGB::red() const { return m_red; }
uint RGB::green() const { return m_green; }
uint RGB::blue() const { return m_blue; }