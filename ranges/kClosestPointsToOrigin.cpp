#include<ranges>
class Solution {
public:

    double l2Norm(vector<int>vec){
        return vec[0] * vec[0] + vec[1] * vec[1]; 
    }


    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        std::ranges::sort(points, [this](auto a, auto b){
            return l2Norm(a) < l2Norm(b); 
        }); 

        vector<vector<int>>dest; 
        dest.reserve(k); 
        // Take first k elements and copy them
        auto view = points | std::views::take(k);

        std::ranges::copy(view, std::back_inserter(dest));

        return dest; 
        
    }
};
