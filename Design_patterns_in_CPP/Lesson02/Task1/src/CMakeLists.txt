cmake_minimum_required(VERSION 3.5)

project(StructuralTemplatesProxyDecoratorAdapter)

set(CMAKE_CXX_STANDARD 17)

add_executable(StructuralTemplatesProxyDecoratorAdapter StructuralTemplatesProxyDecoratorAdapter.cpp)

target_compile_options(StructuralTemplatesProxyDecoratorAdapter PRIVATE -Wall -Wextra -pedantic)


