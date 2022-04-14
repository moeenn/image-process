#include <iostream>
#include "./Timer.hpp"
#include "./ImageParser.hpp"

int main() {
  Timer t{};

  ImageParser p{"in_full.ppm"};
  auto image = p.parse();

  image->save("./out_full.ppm");
}