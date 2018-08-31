cmake_minimum_required(VERSION 3.5)
project(test_range_v3 CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Include the external folder
include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS
  NO_OUTPUT_DIRS)

add_executable(main main.cpp)
target_link_libraries(main CONAN_PKG::range-v3)
