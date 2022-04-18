#include "./ArgsParser.hpp"
#include "./Colors.hpp"
#include "./Filters.hpp"
#include "./ImageParser.hpp"
#include "./Timer.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  Timer t{};
  ArgsParser parser{argc, argv};

  std::string in, out;
  {
    parser.flag("-i", "Input PPM file", &in);
    parser.flag("-o", "Output PPM file", &out);
    parser.parse();
  }

  std::cout << colors::FGRN << "Processing " << in << colors::RS << '\n';

  auto image = ImageParser::parse(in);
  if (!image) {
    std::cerr << colors::FRED << "[error] Failed to read file: " << in
              << colors::RS << '\n';
    return 1;
  }

  image.value()->applyFilters(Filters::grayscale);
  image.value()->save(out);
}
