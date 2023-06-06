cmake_minimum_required(VERSION 3.5)

project(secure_data_exchange)

set(CMAKE_CXX_STANDARD 17)

add_executable(secure_data_exchange secure_data_exchange.cpp)

target_compile_options(secure_data_exchange PRIVATE -Wall -Wextra -pedantic)


