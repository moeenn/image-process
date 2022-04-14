cmake_minimum_required(VERSION 3.5)

set (project_name "image-process")
project (${project_name})

set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra -Werror -Wall -std=c++17 -Wc++17-extensions")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_files "${source_dir}/*.cpp")
add_executable(${project_name} ${source_files})

set(EXECUTABLE_OUTPUT_PATH "bin")
