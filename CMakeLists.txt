cmake_minimum_required(VERSION 3.17)
project(jd_directed_graph)

set(CMAKE_CXX_STANDARD 14)

add_executable(jd_directed_graph main.cpp directed_graph.h directed_graph.cpp)