#pragma once
#include "./Image.hpp"
#include "./RGB.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

namespace ImageParser {
uint toUint(const std::string &str);
std::optional<std::unique_ptr<Image>> parse(const std::string &path);
} // namespace ImageParser
