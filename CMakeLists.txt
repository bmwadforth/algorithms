cmake_minimum_required(VERSION 3.27)
project(algorithms)

set(CMAKE_CXX_STANDARD 23)

add_executable(algorithms main.cpp
        arrays/linear_search.cpp
        arrays/linear_search.h)
