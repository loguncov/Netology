cmake_minimum_required(VERSION 3.5)

project(generating_patterns2)

set(CMAKE_CXX_STANDARD 17)

add_executable(generating_patterns2 generating_patterns2.cpp)

target_compile_options(generating_patterns2 PRIVATE -Wall -Wextra -pedantic)


