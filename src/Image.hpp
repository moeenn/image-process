#pragma once
#include "./RGB.hpp"
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Image {
private:
  uint m_height;
  uint m_width;
  uint m_max_rgb;
  std::string m_type;
  std::vector<RGB> m_content;
  std::ofstream m_file;
  std::function<void(RGB &)> m_filter;

public:
  Image(const uint height, const uint width, const uint max_rgb = 255,
        const std::string &type = "P3");

  uint height() const;
  uint width() const;
  uint max_rgb() const;
  std::string headers() const;

  std::vector<RGB> content() const;
  void applyFilters(std::function<void(RGB &)>);
  void update(const std::vector<RGB> &content);
  void save(const std::string &path);

  ~Image();
};