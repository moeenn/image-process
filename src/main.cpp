#include "./ArgsParser.hpp"
#include "./Timer.hpp"
#include "./ppm.hpp"
#include <filesystem>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  Timer t{};
  ArgsParser parser{argc, argv};

  const char *in, *out;
  {
    parser.flag("-i", "Input PPM file", &in);
    parser.flag("-o", "Output PPM file", &out);
    parser.parse();
  }

  std::ifstream src;
  std::ofstream dest;

  const bool exists = std::filesystem::is_regular_file(in);
  if (!exists) {
    std::cerr << "Failed to open input file\n";
    return 1;
  }

  src.open(in);
  dest.open(out);

  ppm::process(src, dest, [](uint &red, uint &green, uint &blue) {
    const uint avg = (red + green + blue) / 3;
    red = green = blue = avg;
  });
}
