cmake_minimum_required(VERSION 3.5)

project(tridiagonal_matrix_clone)

set(CMAKE_CXX_STANDARD 17)

add_executable(tridiagonal_matrix_clone src/tridiagonal_matrix_clone.cpp)

target_compile_options(tridiagonal_matrix_clone PRIVATE -Wall -Wextra -pedantic)

find_package(Threads REQUIRED)
target_link_libraries(tridiagonal_matrix_clone PRIVATE Threads::Threads)
