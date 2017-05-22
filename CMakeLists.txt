cmake_minimum_required(VERSION 3.7)
project(try2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BinaryTree.cpp BinaryTree.h Node.h)
add_executable(try2 ${SOURCE_FILES})