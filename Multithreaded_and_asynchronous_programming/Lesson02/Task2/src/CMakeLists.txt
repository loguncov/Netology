cmake_minimum_required(VERSION 3.5)

project(progress_bar)

set(CMAKE_CXX_STANDARD 17)

add_executable(progress_bar progress_bar.cpp)

target_compile_options(progress_bar PRIVATE -Wall -Wextra -pedantic)


