#include "./Colors.hpp"
#include "./ImageParser.hpp"
#include "./Timer.hpp"
#include <iostream>
#include <stdexcept>

int main() {
  Timer t{};

  try {
    ImageParser p{"./test_images/ins_full.ppm"};
    auto image = p.parse();

    image->save("./out_full.ppm");
  } catch (const std::runtime_error &err) {
    std::cout << colors::FRED << "[error] " << err.what() << colors::RS << '\n';
  }
}
