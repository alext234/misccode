cmake_minimum_required(VERSION 2.8)

project(lastKLines)

set(GOOGLETEST ${CMAKE_SOURCE_DIR}/../googletest/)  
include_directories(${GOOGLETEST}/googlemock/include ${GOOGLETEST}/googletest/include)
link_directories(${GOOGLETEST}/build/googlemock ${GOOGLETEST}/build/googlemock/gtest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++1y -Wall -Wextra -Wno-unused-parameter")

add_executable(lastKLines main.cpp PrintFile.cpp)

add_executable(testPrintFile testPrintFile PrintFile.cpp)
target_link_libraries(testPrintFile gmock)
target_link_libraries(testPrintFile gtest)
target_link_libraries(testPrintFile pthread)