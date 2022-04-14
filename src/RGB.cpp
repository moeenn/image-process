#include "./RGB.hpp"

uint RGB::s_max_rgb = 255;

RGB::RGB(const uint red, const uint green, const uint blue)
    : m_red(red), m_green(green), m_blue(blue) {
  if (red < 0 || green < 0 || blue < 0 || red > s_max_rgb ||
      green > s_max_rgb || blue > s_max_rgb) {
    std::stringstream ss;
    ss << "Invalid values: (" << red << ' ' << green << ' ' << blue << ")";

    throw std::runtime_error{ss.str()};
  }
}

uint RGB::red() const { return m_red; }
uint RGB::green() const { return m_green; }
uint RGB::blue() const { return m_blue; }