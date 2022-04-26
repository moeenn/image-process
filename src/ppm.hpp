#pragma once
#include <iostream>
#include <array>
#include <fstream>
#include <functional>

namespace ppm {
uint color_code(const uint &i);
void process(std::ifstream& src, std::ofstream& dest, std::function<void(uint&, uint&, uint&)> f);
} // namespace ppm