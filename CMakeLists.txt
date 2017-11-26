cmake_minimum_required(VERSION 3.9)
project(Compiler)

set(CMAKE_CXX_STANDARD 11)

add_executable(Compiler main.cpp CheckStructure.cpp CheckStructure.h)