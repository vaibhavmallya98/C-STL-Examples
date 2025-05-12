#include <algorithm>
#include <iostream>
#include <ranges>
#include <string_view>

class Solution {
public:

    bool isPalindrome(string s) {

        auto alphaNum = s | std::views::filter([](unsigned char c){return std::isalnum(c); })          
        | std::views::transform([](unsigned char c){return std::tolower(c); });  

        std::string lowercase(alphaNum.begin(), alphaNum.end()); 

        return std::ranges::equal(lowercase, lowercase | std::views::reverse);
        
    }
};
