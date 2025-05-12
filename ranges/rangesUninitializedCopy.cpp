#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main() {
    std::vector<int> source = {1, 2, 3, 4, 5};
    
    // Allocate uninitialized memory for 5 integers
    std::vector<int> target(5);  // This is initialized memory, target is already sized
    
    // Copy the data into uninitialized memory (target will be initialized)
    std::ranges::uninitialized_copy(source.begin(), source.end(), target.begin());

    // Output the copied values
    for (auto val : target) {
        std::cout << val << " ";  // Should print: 1 2 3 4 5
    }

    return 0;
}
