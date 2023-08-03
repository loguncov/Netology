cmake_minimum_required(VERSION 3.5)

project(VeryHeavyDatabase)

set(CMAKE_CXX_STANDARD 17)

add_executable(VeryHeavyDatabase VeryHeavyDatabase.cpp)

target_compile_options(VeryHeavyDatabase PRIVATE -Wall -Wextra -pedantic)


