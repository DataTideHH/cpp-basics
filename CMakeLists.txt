cmake_minimum_required(VERSION 3.20)
project(cpp_basics)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_basics
        src/main.cpp
        src/subnet.cpp
        include/subnet.h
)

target_include_directories(cpp_basics PRIVATE include)
