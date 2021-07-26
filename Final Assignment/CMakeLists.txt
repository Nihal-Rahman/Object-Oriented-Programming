cmake_minimum_required(VERSION 3.17)
project(hw08)

set(CMAKE_CXX_STANDARD 14)

add_executable(hw08 hw08.cpp)
add_executable(seperate_comp test.cpp Polynomial.h Polynomial.cpp)