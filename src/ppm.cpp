#include "./ppm.hpp"

/**
 *  color index:
 *  0: red
 *  1: green
 *  2: blue
 */
uint ppm::color_code(const uint &i) { return (i - 5) % 3; }

/**
 *  read input image, process pixel values and write output image
 */
void ppm::process(std::ifstream &src, std::ofstream &dest,
                  std::function<void(uint &, uint &, uint &)> f) {
  uint s_count, col_index, avg;
  s_count = avg = col_index = 0;

  std::array<uint, 3> color;
  std::string symbol;
  symbol.reserve(5);

  while (!src.eof()) {
    src >> symbol;
    s_count++;

    /** the first four symbols are header information */
    if (s_count < 5) {
      dest << symbol << '\n';
      continue;
    }

    col_index = color_code(s_count);
    /** convert std::string to uint */
    color[col_index] = std::stoul(symbol, nullptr, 0);

    if (col_index == 2) {
      f(color[0], color[1], color[2]);
      dest << color[0] << ' ' << color[1] << ' ' << color[2] << ' ';
    }
  }
}