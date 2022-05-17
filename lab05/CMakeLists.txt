cmake_minimum_required(VERSION 3.20)
project(p)

set(CMAKE_CXX_STANDARD 14)

add_executable(p main.cpp functions.h stack.h func.cpp TESTS.cpp TESTS.h)
