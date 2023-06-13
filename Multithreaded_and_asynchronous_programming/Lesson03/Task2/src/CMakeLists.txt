cmake_minimum_required(VERSION 3.5)

project(for_each)

set(CMAKE_CXX_STANDARD 17)

add_executable(for_each for_each.cpp)

target_compile_options(for_each PRIVATE -Wall -Wextra -pedantic)


