cmake_minimum_required(VERSION 3.22)
project(loginSystem_A4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(loginSystem_A4
        LoginApp.cpp
        LoginFunctions.cpp
        LoginFunctions.h)
