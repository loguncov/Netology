cmake_minimum_required(VERSION 3.5)

project(printable)

set(CMAKE_CXX_STANDARD 17)

add_executable(printable printable.cpp)

target_compile_options(printable PRIVATE -Wall -Wextra -pedantic)


