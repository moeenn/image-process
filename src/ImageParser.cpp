#include "./ImageParser.hpp"

uint ImageParser::toUint(const std::string &str) {
  uint result;
  std::istringstream reader(str);

  reader >> result;
  return result;
}

std::optional<std::unique_ptr<Image>> ImageParser::parse(const std::string &path) { 
  const bool exists = std::filesystem::is_regular_file(path);
  if (!exists) {
    return {};
  }

  std::ifstream file;
  file.open(path); 

  std::string type, height, width, max_rgb, red, green, blue;
  file >> type >> width >> height >> max_rgb;

  uint uint_height = toUint(height), uint_width = toUint(width),
       uint_max_rgb = toUint(max_rgb);

  std::vector<RGB> content;
  content.reserve(uint_height * uint_width);

  while (!file.eof()) {
    file >> red >> green >> blue;
    RGB rgb{toUint(red), toUint(green), toUint(blue)};
    content.push_back(rgb);
  }

  auto image =
      std::make_unique<Image>(uint_height, uint_width, uint_max_rgb, type);
  image->update(content);

  return image;
}
