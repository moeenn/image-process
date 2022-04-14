cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra -Wall -std=c++17 -Wc++17-extensions")

project(image-process)

add_executable(
  image-process
  src/main.cpp
  src/Timer.cpp
  src/RGB.cpp
  src/Image.cpp
  src/ImageParser.cpp
)

set(EXECUTABLE_OUTPUT_PATH "bin")
