cmake_minimum_required(VERSION 3.5)

project(parallel)

set(CMAKE_CXX_STANDARD 17)

add_executable(parallel parallel.cpp)

target_compile_options(parallel PRIVATE -Wall -Wextra -pedantic)


