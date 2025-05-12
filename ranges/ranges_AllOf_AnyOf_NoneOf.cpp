#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm> // for ranges::all_of, any_of, none_of

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Check if all elements are positive
    bool all_positive = std::ranges::all_of(numbers, [](int x) { return x > 0; });

    // Check if any element is even
    bool any_even = std::ranges::any_of(numbers, [](int x) { return x % 2 == 0; });

    // Check if none of the elements are negative
    bool none_negative = std::ranges::none_of(numbers, [](int x) { return x < 0; });

    auto DivisibleBy = [](int d)
    {
        return [d](int m) { return m % d == 0; };
    };
 
    if (ranges::any_of(numbers, DivisibleBy(7)))
        std::cout << "At least one number is divisible by 7\n";
    else{
        std::cout << "None of the numbers in the vector are divisible by 7\n"; 
    }

    std::cout << std::boolalpha;
    std::cout << "All positive? " << all_positive << "\n";    // true
    std::cout << "Any even? "     << any_even     << "\n";    // true
    std::cout << "None negative? " << none_negative << "\n";  // true

    return 0;
}
