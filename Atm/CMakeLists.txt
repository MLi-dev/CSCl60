cmake_minimum_required(VERSION 3.21)
project(Atm)

set(CMAKE_CXX_STANDARD 14)

add_executable(Atm main.cpp bankaccount.cpp bankaccount.h atm.cpp atm.h)
