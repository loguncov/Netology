cmake_minimum_required(VERSION 3.5)

project(customers)

set(CMAKE_CXX_STANDARD 17)

add_executable(customers customers.cpp)

target_compile_options(customers PRIVATE -Wall -Wextra -pedantic)


