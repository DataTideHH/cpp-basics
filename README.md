# C++ Basics

A small C++20 setup and learning repository for my local developer environment on an Intel iMac running macOS Sonoma.

This repository verifies that a modern C++ workflow works correctly with CLion, CMake, Ninja, Apple clang++, Git, and GitHub.

## Purpose

This is not intended to be a large C++ application. It is a compact baseline project for:

- verifying the local C++ toolchain
- practicing C++ fundamentals
- understanding compiled languages and build systems
- preparing for small command-line tools later on
- keeping a clean Git/GitHub workflow for C++ projects

C++ is a secondary technical skill in my current learning path. My main focus is data and process analysis, SQL, Python, BI, and Microsoft-oriented data tooling.

## Environment

- macOS Sonoma on Intel iMac
- CLion
- Apple clang++
- CMake
- Ninja
- C++20
- Git / GitHub

## Repository Structure

    .
    ├── CMakeLists.txt
    ├── main.cpp
    ├── README.md
    └── .gitignore

Build directories such as `build/` and `cmake-build-debug/` are intentionally excluded from Git.

## Build from Terminal

Configure the project:

    cmake -S . -B build -G Ninja

Build the executable:

    cmake --build build

Run the program:

    ./build/cpp_basics

Expected output:

    C++ läuft sauber mit CLion/CMake.
    Summe: 100

## What This Demonstrates

This repository demonstrates a working C++20 baseline setup using:

- a CMake-based project structure
- Ninja as build generator
- Apple clang++ as compiler
- CLion as the primary C++ IDE
- Git and GitHub for version control

## Next Steps

Possible future additions:

- a small subnetting calculator
- a simple CSV checker
- a logfile parser
- basic unit tests
- a more structured `src/` and `include/` layout

## Notes

This repository is intentionally small. Its purpose is to document and verify a clean C++ development setup before building larger tools.
