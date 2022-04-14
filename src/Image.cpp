#include "./Image.hpp"

Image::Image(const uint height, const uint width, const uint max_rgb,
             const std::string &type)
    : m_height(height), m_width(width), m_max_rgb(max_rgb), m_type(type) {
  const uint max_pixels = m_height * m_width;
  m_content.reserve(max_pixels);
}

uint Image::height() const { return m_height; }
uint Image::width() const { return m_width; }
uint Image::max_rgb() const { return m_max_rgb; }

std::string Image::headers() const {
  std::stringstream ss;
  ss << "P3" << '\n' << m_width << ' ' << m_height << '\n' << m_max_rgb << '\n';

  return ss.str();
}

std::vector<RGB> Image::content() const { return m_content; }
void Image::update(const std::vector<RGB> &content) { m_content = content; }

void Image::save(const std::string &path) {
  if (!m_file.is_open()) {
    m_file.open(path);
  }

  m_file << this->headers();

  for (const RGB &color : m_content) {
    m_file << color.red() << ' ' << color.green() << ' ' << color.blue()
           << '\n';
  }
}

Image::~Image() { m_file.close(); }