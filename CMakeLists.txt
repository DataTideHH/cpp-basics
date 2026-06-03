cmake_minimum_required(VERSION 3.20)
project(cpp_basics LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cpp_basics
        src/main.cpp
        src/subnet.cpp
        include/subnet.h
)

target_include_directories(cpp_basics PRIVATE include)

# Reasonable warnings. Beginner-friendly: warns, but does not fail the build.
target_compile_options(cpp_basics PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall;-Wextra;-Wpedantic>
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
)
