#include <iostream>
#include <vector>
#include <ranges>  // for std::ranges

int main() {
    std::vector<int> v = {10, 20, 30, 40, 50};

    // Count number of elements in the whole vector
    auto dist1 = std::ranges::distance(v);
    std::cout << "Total elements: " << dist1 << "\n";

    // Count number of elements from 2nd to 4th element (20 to 40)
    auto dist2 = std::ranges::distance(v.begin() + 1, v.begin() + 4);
    std::cout << "Elements from 2nd to 4th: " << dist2 << "\n";

    return 0;
}
