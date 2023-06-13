cmake_minimum_required(VERSION 3.5)

project(sorting_selection)

set(CMAKE_CXX_STANDARD 17)

add_executable(sorting_selection sorting_selection.cpp)

target_compile_options(sorting_selection PRIVATE -Wall -Wextra -pedantic)


