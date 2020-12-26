cmake_minimum_required(VERSION 3.17)
project(SO)

set(CMAKE_CXX_STANDARD 14)

add_executable(SO main.cpp Algorithms.cpp Algorithms.h Controller.cpp Controller.h)