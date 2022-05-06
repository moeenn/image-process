#include "./ArgsParser.hpp"
#include "./Timer.hpp"
#include "./ppm.hpp"
#include "./filters.hpp"
#include <filesystem>
#include <iostream>
#include <string>

void print_help() {
  std::cout << "usage:\n\n"
            << "-i\tInput PPM file\n"
            << "-o\tOutput PPM file\n"
            << "-d\tDarken Image. Value between 1 and 100\n\n";
}

int main(int argc, char *argv[]) {
  Timer t{};
  ArgsParser parser{argc, argv};

  auto in = parser.String("-i");
  auto out = parser.String("-o");
  auto darken = parser.Int("-d");

  if (!in || !out) {
    print_help();
    return 1;
  }

  std::ifstream src;
  std::ofstream dest;

  const bool exists = std::filesystem::is_regular_file(*in);
  if (!exists) {
    std::cerr << "Failed to open input file\n";
    return 1;
  }

  src.open(*in);
  dest.open(*out);

  ppm::process(src, dest, [&](uint &r, uint &g, uint &b) {
    filters::grayscale(r, g, b);

    if (darken) {
      filters::darken(1.0f - (*darken / 100.0f), r, g ,b);
    }
  });
}