#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>  // For std::ranges::destroy, std::ranges::uninitialized_copy

int main() {
    // Initial vector with some data
    std::vector<int> v = {1, 2, 3, 4, 5};

    // Destroying the contents of the vector (equivalent to calling .clear(), but explicitly freeing resources)
    std::ranges::destroy(v.begin(), v.end());
    std::cout << "After destroy: ";
    for (int val : v) {
        std::cout << val << " ";  // This will print 0s, as the elements are destroyed but still exist
    }
    std::cout << "\n";
}
