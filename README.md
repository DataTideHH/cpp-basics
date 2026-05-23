# C++ Basics

Small C++ setup test project for my iMac developer environment.

## Environment

- macOS Sonoma on Intel iMac
- CLion
- Apple clang++
- CMake
- Ninja
- C++20

## Purpose

This repository verifies that my local C++ toolchain works correctly with CLion, CMake, Ninja, and Apple clang++.

C++ is used here as a secondary technical skill for understanding compiled languages, build systems, basic performance concepts, and small command-line tools.

## Build from Terminal

Configure the project:

    cmake -S . -B build -G Ninja

Build:

    cmake --build build

Run:

    ./build/cpp_basics

## Notes

Build directories are intentionally excluded from Git.
