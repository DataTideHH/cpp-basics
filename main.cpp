#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> values {10, 20, 30, 40};
    int sum = std::accumulate(values.begin(), values.end(), 0);

    std::cout << "C++ läuft sauber mit CLion/CMake." << '\n';
    std::cout << "Summe: " << sum << '\n';

    return 0;
}
