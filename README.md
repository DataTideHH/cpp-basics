# C++ Basics

A small C++20 setup and learning repository for my local developer environment.

This repository verifies that a modern C++ workflow works correctly with CLion, CMake, Ninja, Apple clang++, Git, and GitHub on my Intel Mac setup.

## Purpose

This is not intended to be a large C++ application. It is a compact baseline project for:

- verifying the local C++ toolchain
- practicing C++ fundamentals
- understanding compiled languages and build systems
- preparing for small command-line tools later on
- keeping a clean Git/GitHub workflow for C++ projects

C++ is a secondary technical skill in my current learning path. My main focus is data and process analysis, SQL, Python, BI, and Microsoft-oriented data tooling.

## Tested Environment

- iMac Retina 4K, 21.5-inch, Late 2015
- Intel x86_64
- macOS Sonoma 14.8.7 via OpenCore Legacy Patcher
- CLion via JetBrains Toolbox
- Apple clang++ 16
- CMake 4.3.2
- Ninja 1.13.2
- C++20
- Git / GitHub

This repository also documents that the toolchain works on a legacy Intel Mac setup used as a stable learning and development machine.

## Repository Structure

    .
    ├── CMakeLists.txt
    ├── include/
    │   └── subnet.h
    ├── src/
    │   ├── main.cpp
    │   └── subnet.cpp
    ├── README.md
    ├── LICENSE
    ├── .clang-format
    ├── .editorconfig
    └── .gitignore

Build directories and local IDE metadata are intentionally excluded from Git:

```text
.idea/
build/
cmake-build-debug/
```

## Run in CLion

Open the project in CLion and run the `cpp_basics` configuration.

Program arguments:

    192.168.10.42/24

Expected output:

    Input IP:          192.168.10.42
    CIDR prefix:       /24
    Subnet mask:       255.255.255.0
    Wildcard mask:     0.0.0.255
    Network address:   192.168.10.0
    Broadcast address: 192.168.10.255
    Total addresses:   256
    Usable hosts:      254
    First usable host: 192.168.10.1
    Last usable host:  192.168.10.254
    Note:              Standard subnet with network and broadcast addresses excluded.

## Build from Terminal

Configure the project:

    cmake -S . -B build -G Ninja

Build the executable:

    cmake --build build

Run the subnet calculator:

    ./build/cpp_basics 192.168.10.42/24

Expected output:

    Input IP:          192.168.10.42
    CIDR prefix:       /24
    Subnet mask:       255.255.255.0
    Wildcard mask:     0.0.0.255
    Network address:   192.168.10.0
    Broadcast address: 192.168.10.255
    Total addresses:   256
    Usable hosts:      254
    First usable host: 192.168.10.1
    Last usable host:  192.168.10.254
    Note:              Standard subnet with network and broadcast addresses excluded.

## What This Demonstrates

This repository demonstrates a working C++20 baseline setup using:

- a CMake-based project structure
- a small command-line IPv4 subnet calculator
- IPv4 parsing and validation
- CIDR prefix handling
- subnet mask and wildcard mask calculation
- network and broadcast address calculation
- basic bitwise operations in C++
- Ninja as build generator
- Apple clang++ as compiler
- CLion as the primary C++ IDE
- Git and GitHub for version control

## Next Steps

Possible future additions:

- a simple CSV checker
- a logfile parser
- basic unit tests

## Notes

This repository is intentionally small. Its purpose is to document and verify a clean C++ development setup before building larger tools.

No local build artifacts, IDE metadata, or machine-specific files are committed.
