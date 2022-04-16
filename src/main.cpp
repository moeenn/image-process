#include "./Colors.hpp"
#include "./Filters.hpp"
#include "./ImageParser.hpp"
#include "./Timer.hpp"
#include <iostream>
#include <unordered_map>

int main() {
  Timer t{};

  std::unordered_map<std::string, std::string> images{
      {"./test_images/01.ppm", "./test_images/01_out.ppm"},
      {"./test_images/02.ppm", "./test_images/02_out.ppm"},
      {"./test_images/03.ppm", "./test_images/03_out.ppm"},
      { "./test_images/04.ppm", "./test_images/04_out.ppm" },
  };

  for (const auto&[src, dest] : images ) {
    auto image = ImageParser::parse(src);
    if (!image) {
      std::cerr << colors::FRED << "[error] Failed to read file" << colors::RS
                << '\n';
      return 1;
    }

    Filters::grayscale(*(image.value()));
    image.value()->save(dest);
  }
}
