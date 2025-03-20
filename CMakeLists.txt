cmake_minimum_required(VERSION 3.14)
project(Graphs)

configure_file(${CMAKE_SOURCE_DIR}/graph.txt
               ${CMAKE_CURRENT_BINARY_DIR}/graph.txt
               COPYONLY)
               
add_executable(Graphs solution.cpp)