#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include "./Image.hpp"
#include "./RGB.hpp"

class ImageParser {
private:
  std::ifstream m_file;
  std::vector<RGB> m_content;

  uint toUint(const std::string &str);

public:
  ImageParser(const std::string &path);
  std::unique_ptr<Image> parse();

  ~ImageParser();
};
