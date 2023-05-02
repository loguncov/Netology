cmake_minimum_required(VERSION 3.5)

project(moving_objects)

set(CMAKE_CXX_STANDARD 17)

add_executable(moving_objects moving_objects.cpp)

target_compile_options(moving_objects PRIVATE -Wall -Wextra -pedantic)


