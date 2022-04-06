cmake_minimum_required(VERSION 3.21)
project(algoritm)

set(CMAKE_CXX_STANDARD 14)

include_directories(lab01/Voridan/Sort)
include_directories(lab02/Voridan)
add_executable(algoritm
        lab01/Voridan/Sort/main.cpp
        lab01/Voridan/Sort/sorts.cpp
        lab01/Voridan/Sort/sorts.h
        lab01/Voridan/Sort/tests.cpp
        lab01/Voridan/Sort/tests.h)
