cmake_minimum_required(VERSION 3.5)

project(generating_patterns)

set(CMAKE_CXX_STANDARD 17)

add_executable(generating_patterns generating_patterns.cpp)

target_compile_options(generating_patterns PRIVATE -Wall -Wextra -pedantic)


