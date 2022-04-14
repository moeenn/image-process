#include "./Filters.hpp"

void Filters::grayscale(Image &image) {
  auto current_content = image.content();
  std::vector<RGB> updated_content{};

  for (const RGB &rgb : current_content) {
    const uint red = rgb.red(), green = rgb.green(), blue = rgb.blue();

    const uint avg = (red + green + blue) / 3;
    updated_content.push_back(RGB{avg, avg, avg});
  }

  image.update(updated_content);
}