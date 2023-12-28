cmake_minimum_required(VERSION 3.10)
project(number-to-engl)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(cpp-number-to-engl src/main.cpp src/decimal_conversions.cpp
    src/digit_conversions.cpp)
target_include_directories(cpp-number-to-engl PRIVATE include)