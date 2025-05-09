#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

int main(){
    std::vector<int> original_vector = {1,2,3,4,5}; 
    std::vector<int> copied_vector = original_vector; 

    std::cout<<"Copied vector: "; 
    std::copy(copied_vector.begin(), copied_vector.end(), std::ostream_iterator<int>(std::cout, "|"));
    std::cout<<std::endl; 
}