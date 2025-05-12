#include <iostream>
#include <vector>
#include <algorithm>    // for std::ranges::upper_bound
#include <ranges>

int main() {
    std::vector<int> v = {1, 3, 3, 5, 7, 9};

    // Find the first element GREATER than 3
    auto it = std::ranges::upper_bound(v, 3);

    if (it != v.end()) {
        std::cout << "First element greater than 3 is: " << *it << "\n";
    } else {
        std::cout << "No element greater than 3 found.\n";
    }

    return 0;
}
