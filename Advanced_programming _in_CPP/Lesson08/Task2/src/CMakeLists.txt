cmake_minimum_required(VERSION 3.5)

project(elimination_of_the_intersection)

set(CMAKE_CXX_STANDARD 17)

add_executable(elimination_of_the_intersection elimination_of_the_intersection.cpp)

target_compile_options(elimination_of_the_intersection PRIVATE -Wall -Wextra -pedantic)

find_package(Threads REQUIRED)
target_link_libraries(elimination_of_the_intersection PRIVATE Threads::Threads)
