#include<vector>
#include<iostream>
#include<ranges>
#include<algorithm>
#include<math.h>
#include<map>
#include <unordered_map>

double l2Norm(std::pair<double,double> point ){

    return sqrt(pow(point.first,2) + pow(point.second,2)); 

}

int main(){

    std::vector<std::pair<double,double>> coordinates = {{3.57,4.63}, {7.31,6.54}, {2.45, 3.21}}; 
    
    //{} - signifies the default operator < (less than) 
    auto largestL2Norm = std::ranges::max_element(coordinates, {}, l2Norm);

    std::cout<<"Coordinate with the largest L2 Norm is ("<<largestL2Norm->first<<", "<<largestL2Norm->second<<"). "; 
    std::cout<<"Its L2 norm is "<<l2Norm(*largestL2Norm); 

    // Sort using lambda comparator
    std::ranges::sort(coordinates, [](auto a, auto b) {
        return l2Norm(a) < l2Norm(b);
    });

    // Print sorted
    std::cout<<"\n"; 
    for (const auto& [x, y] : coordinates) {
        std::cout << "(" << x << ", " << y << ")\n";
    }
    
}
