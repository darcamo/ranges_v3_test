cmake_minimum_required(VERSION 3.5)
project(test_range_v3 CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Include the external folder
include_directories(SYSTEM external/range-v3/include)

add_executable(main main.cpp)
