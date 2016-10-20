cmake_minimum_required(VERSION 2.8)

project(lastKLines)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++1y -Wall -Wextra -Wno-unused-parameter")

add_executable(lastKLines main.cpp PrintFile.cpp)
