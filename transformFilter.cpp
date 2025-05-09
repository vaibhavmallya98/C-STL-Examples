#include<vector>
#include<iostream>
#include<algorithm>
#include<ranges> 


int main(){

    //Example 1 - unary operation 
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> result1(v.size());

    std::transform(v.begin(), v.end(), result1.begin(), [](int x) {
        return x * x;
    });

    for (int x : result1)
        std::cout << x << " ";

    std::cout<<"\n";



    //Example 2 - binary operation 
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {4, 5, 6};
    std::vector<int> result2(3);

    std::transform(a.begin(), a.end(), b.begin(), result2.begin(), [](int x, int y) {
        return x + y;
    });

    for (int x : result2)
        std::cout << x << " ";



    //Example 3 - filter and transform  
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9,10}; 

    //evenSquared is a view,  we can use any containers that use iterators 
    auto evenSquared = vec | std::views::filter([](int x){return x % 2 == 0; }) | std::views::transform([](int x){return x * x; });
    
    for(auto n: evenSquared){
        std::cout<<n<<" "; 
    }
    std::cout<<"\n"; 



    //Example 4 - 
    std::vector<std::string> words = {"hello", "earthlings"};
    std::vector<size_t> lengths;

    //the below is the same thing as lengths.pushback(word.size()) where word is an element of the string vector words 
    std::transform(words.begin(), words.end(), std::back_inserter(lengths),
               [](const std::string& s) { return s.length(); });


    for(auto l: lengths){
        std::cout<<l<<" "; 
    }
    std::cout<<"\n"; 

}