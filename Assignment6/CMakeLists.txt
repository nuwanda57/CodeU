cmake_minimum_required(VERSION 3.7)
project(A6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CParkingLot.cpp CParkingLot.h tests.cpp tests.h)
add_executable(A6 ${SOURCE_FILES})