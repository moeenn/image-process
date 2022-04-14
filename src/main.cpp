#include "./Colors.hpp"
#include "./Filters.hpp"
#include "./ImageParser.hpp"
#include "./Timer.hpp"
#include <iostream>
#include <stdexcept>

void report(const std::runtime_error &error) {
  std::cerr << colors::FRED << "[error] " << error.what() << colors::RS << '\n';
}

int main() {
  Timer t{};

  auto image = ImageParser::parse("./in.ppm");
  if (!image) {
    auto error = std::runtime_error{"Failed to read file"};
    report(error);
    return 1;
  }

  try {
    Filters::grayscale(*(image.value()));
    image.value()->save("./out_full.ppm");
  } catch (const std::runtime_error &err) {
    report(err);
    return 1;
  }
}
