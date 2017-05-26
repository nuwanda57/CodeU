cmake_minimum_required(VERSION 3.7)
project(week_2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES w2_q1.cpp w2_BinaryTree.cpp w2_BinaryTree.h w2_Node.h w2_q2.cpp w2_main.cpp w2_q1.h w2_q2.h CreateBinaryTree.cpp CreateBinaryTree.h)
add_executable(week_2 ${SOURCE_FILES})