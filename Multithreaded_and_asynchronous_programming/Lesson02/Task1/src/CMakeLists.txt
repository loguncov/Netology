cmake_minimum_required(VERSION 3.5)

project(automatic_queue)

set(CMAKE_CXX_STANDARD 17)

add_executable(automatic_queue automatic_queue.cpp)

target_compile_options(automatic_queue PRIVATE -Wall -Wextra -pedantic)


