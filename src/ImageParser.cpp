#include "./ImageParser.hpp"

ImageParser::ImageParser(const std::string &path) { 
  const bool exists = std::filesystem::is_regular_file(path);
  if (!exists) {
    std::stringstream ss;
    ss << "File not found: " << path;

    throw std::runtime_error{ss.str()};
  }

  m_file.open(path); 
}

uint ImageParser::toUint(const std::string &str) {
  uint result;
  std::istringstream reader(str);

  reader >> result;
  return result;
}

std::unique_ptr<Image> ImageParser::parse() {
  std::string type, height, width, max_rgb, red, green, blue;
  m_file >> type >> width >> height >> max_rgb;

  uint uint_height = this->toUint(height), uint_width = this->toUint(width),
       uint_max_rgb = this->toUint(max_rgb);

  m_content.reserve(uint_height * uint_width);

  while (!m_file.eof()) {
    m_file >> red >> green >> blue;
    RGB rgb{this->toUint(red), this->toUint(green), this->toUint(blue)};
    m_content.push_back(rgb);
  }

  auto image =
      std::make_unique<Image>(uint_height, uint_width, uint_max_rgb, type);
  image->update(m_content);

  return image;
}

ImageParser::~ImageParser() { m_file.close(); }