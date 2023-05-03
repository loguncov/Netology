cmake_minimum_required(VERSION 3.5)

project(large_numbers)

set(CMAKE_CXX_STANDARD 17)

add_executable(large_numbers large_numbers.cpp)

target_compile_options(large_numbers PRIVATE -Wall -Wextra -pedantic)


