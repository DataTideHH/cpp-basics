# C++ Basics — Historical Baseline

> **Archived learning snapshot.** Active development of the IPv4 subnet calculator has moved to [IPv4 Subnet Calculator Multilang](https://datatidehh.github.io/ipv4-subnet-calculator-multilang/).

This repository is retained as a historical record of the initial C++20 toolchain setup and the first standalone C++ version of the calculator.

## Why this repository is archived

The calculator was consolidated into one stronger portfolio repository that now provides:

- aligned Java 21, C++20 and Python 3.12 implementations
- one normative behavior specification
- interactive, direct and help modes
- shared fachliche contract cases
- language-specific tests
- GitHub Actions
- a dedicated project page

Keeping the original copy active would duplicate the same small application and weaken the portfolio structure.

## Preserved historical scope

This snapshot documents:

- C++20
- CLion
- CMake and Ninja
- a header/source project split
- `std::string_view` and `std::from_chars`
- fixed-width IPv4 integer types
- IPv4/CIDR parsing and bitwise subnet calculation
- local build output excluded from Git
- cross-platform learning use on an Intel iMac and Windows ThinkPad

## Historical commands

Configure and build:

```text
cmake -S . -B build -G Ninja
cmake --build build
```

Run the calculator:

```text
./build/cpp_basics 192.168.10.42/24
```

## Canonical successor

Use the maintained project for current code, tests and documentation:

- Project page: https://datatidehh.github.io/ipv4-subnet-calculator-multilang/
- Repository: https://github.com/DataTideHH/ipv4-subnet-calculator-multilang

## Status

Historical snapshot. No further feature development is planned in this repository.
