# C++ Basics

A small C++20 learning project that verifies my local C++ toolchain and includes a command-line IPv4 subnet calculator.

This repository verifies that a modern C++ workflow works correctly with CLion, CMake, Ninja, Git and GitHub across my Intel Mac and Windows ThinkPad setup.

## Purpose

This is not intended to be a large C++ application.

It is a compact baseline project for:

- verifying the local C++ toolchain
- practicing C++ fundamentals
- understanding compiled languages and build systems
- working with CMake and Ninja
- using CLion as the primary C++ IDE
- keeping IDE metadata and build output out of Git
- documenting small command-line C++ exercises
- maintaining a clean Git/GitHub workflow for C++ projects

C++ is a secondary technical skill in my current learning path. My main focus remains data and process analysis, SQL, Python, BI and Microsoft-oriented data tooling.

## Tested Environment

The project is used across my current developer setup:

- iMac Retina 4K, 21.5-inch, Late 2015
- Intel x86_64
- macOS Sonoma via OpenCore Legacy Patcher
- CLion via JetBrains Toolbox
- Apple clang++ on macOS
- Lenovo ThinkPad X1 Carbon Gen 9
- Windows 11 Enterprise
- CLion on Windows
- CMake
- Ninja
- C++20
- Git / GitHub
- Claude Code as an optional project assistant in the terminal

This repository also documents that the C++20 workflow works on a legacy Intel Mac setup and on a Windows ThinkPad used as a mirrored learning and development machine.

## Repository Structure

```text
cpp-basics/
├── CMakeLists.txt
├── include/
│   └── subnet.h
├── src/
│   ├── main.cpp
│   └── subnet.cpp
├── .clang-format
├── .editorconfig
├── .gitignore
├── LICENSE
└── README.md
```

Local CLion / JetBrains metadata, build directories and compiled binaries are intentionally excluded from Git:

```text
.idea/
build/
build-*/
cmake-build-*/
*.exe
*.o
*.obj
*.out
*.dSYM/
CLAUDE.md
```

## Source Files

| File | Purpose |
|---|---|
| `include/subnet.h` | Public declarations for the subnet calculator logic |
| `src/main.cpp` | Command-line entry point, usage text and result printing |
| `src/subnet.cpp` | IPv4 parsing, CIDR handling and subnet calculation logic |

## Run in CLion

Open the project in CLion and run the `cpp_basics` configuration.

Program arguments:

```text
192.168.10.42/24
```

Expected output:

```text
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
```

## Build from Terminal

Configure the project with CMake and Ninja:

```powershell
cmake -S . -B build -G Ninja
```

Build the project:

```powershell
cmake --build build
```

Run the IPv4 subnet calculator on Windows:

```powershell
.\build\cpp_basics.exe 192.168.10.42/24
```

Run the IPv4 subnet calculator on macOS or Linux:

```zsh
./build/cpp_basics 192.168.10.42/24
```

Depending on the local CLion/CMake generator settings, the executable may also be created inside a `cmake-build-*` directory.

## IPv4 Subnet Calculator

The calculator accepts input in this format:

```text
IPv4/CIDR
```

Examples:

```text
192.168.10.42/24
10.0.0.5/30
0.0.0.0/0
255.255.255.255/32
```

The calculator prints:

- subnet mask
- wildcard mask
- network address
- broadcast address
- total address count
- usable host count
- first usable host
- last usable host
- a short note for standard, `/31` and `/32` subnet cases

## What This Demonstrates

This repository demonstrates a working C++20 baseline setup using:

- CLion as the primary C++ IDE
- CMake as the build configuration system
- Ninja as a fast build backend
- a simple `include/` and `src/` project structure
- C++20 configured in `CMakeLists.txt`
- `std::optional` for validation results
- `std::string_view` for lightweight string handling
- `std::from_chars` for numeric parsing
- fixed-width integer types from `<cstdint>`
- IPv4 parsing and CIDR prefix handling
- subnet mask and wildcard mask calculation
- network and broadcast address calculation
- basic bitwise operations in C++
- `.clang-format` and `.editorconfig` for consistent formatting
- local build output excluded from Git
- Git and GitHub for version control

## Development Workflow

Before working on the repository:

```powershell
git status -sb
git pull --ff-only
```

After making changes:

```powershell
git status -sb
git diff
```

Only intentional source or documentation changes should be committed.

## Next Steps

Possible future additions:

- add clearer validation messages for invalid subnet input
- add basic unit tests later on
- document compiler differences between Apple clang++, GNU g++ and MSVC where relevant

## Notes

This repository is intentionally small.

Its purpose is to document and verify a clean C++20 development setup before building larger C++ exercises or tools.

No IDE metadata, build output or machine-specific files are committed.
