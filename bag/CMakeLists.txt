cmake_minimum_required(VERSION 3.21)
project(bag)

set(CMAKE_CXX_STANDARD 14)

add_executable(bag main.cpp bag.cpp bag.h)
