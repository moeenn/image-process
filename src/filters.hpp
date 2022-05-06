#pragma once
#include <iostream>

namespace filters {
uint normalize(const uint &c);
void grayscale(uint &r, uint &g, uint &b);
void darken(const float &factor, uint &r, uint &g, uint &b);
} // namespace filters
