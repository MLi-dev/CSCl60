cmake_minimum_required(VERSION 3.21)
project(biguint)

set(CMAKE_CXX_STANDARD 14)

add_executable(biguint main.cpp biguint.cpp biguint.h)
