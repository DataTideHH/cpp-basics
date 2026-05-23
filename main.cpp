#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> values{10, 20, 30, 40};
    int sum = std::accumulate(values.begin(), values.end(), 0);

    std::cout << "C++ runs cleanly with CLion/CMake." << '\n';
    std::cout << "Sum: " << sum << '\n';

    return 0;
}
