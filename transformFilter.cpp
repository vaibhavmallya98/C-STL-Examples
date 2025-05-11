#include<vector>
#include<iostream>
#include<algorithm>
#include<ranges> 
#include <utility>
#include<string> 
#include <cctype>
#include <iomanip>
#include<numeric> 

char to_uppercase(unsigned char c)
{
    return std::toupper(c);
}

int squared(int x){
    return x*x; 
}


int main(){

    //Example 1 - unary operation 
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> result1(v.size());

    std::transform(v.begin(), v.end(), result1.begin(), [](int x) {
        return x * x;
    });
    
    std::cout<<"\nUnary operation result: ";

    for (int x : result1)
        std::cout << x << " ";

    //std::cout<<"\n";



    //Example 2 - binary operation 
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {4, 5, 6};
    std::vector<int> result2(3);

    std::transform(a.begin(), a.end(), b.begin(), result2.begin(), [](int x, int y) {
        return x + y;
    });

    std::cout<<"\nBinary operation result: ";
    
    for (int x : result2)
        std::cout << x << " ";



    //Example 3 - filter and transform  
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9,10}; 

    //evenSquared is a view,  we can use any containers that use iterators 
    auto evenSquared = vec | std::views::filter([](int x){return x % 2 == 0; }) | std::views::transform([](int x){return x * x; });
    
    std::cout<<"\nFilter and transform result: "; 
    for(auto n: evenSquared){
        std::cout<<n<<" "; 
    }
    //std::cout<<"\n"; 



    //Example 4 - 
    std::vector<std::string> words = {"hello", "earthlings"};
    std::vector<size_t> lengths;

    //the below is the same thing as lengths.pushback(word.size()) where word is an element of the string vector words 
    std::transform(words.begin(), words.end(), std::back_inserter(lengths),
               [](const std::string& s) { return s.length(); });


    std::cout<<"\nBack inserter result: "; 
    for(auto l: lengths){
        std::cout<<l<<" "; 
    }
    //std::cout<<"\n"; 
    
    //Example 5 - transform using your own function 
    
    std::string st1 = "sample";
    std::transform(st1.cbegin(), st1.cend(), st1.begin(), to_uppercase); 
    std::cout << "\nst1 as uppercase = " << std::quoted(st1);

    //Example 6 - transform vector using your own function
    std::vector<int> vec1 = {1, 3, 3, 5, 7, 9};
    
    std::transform(vec1.begin(),vec1.end(),vec1.begin(),squared);
    
    for(auto n: vec1){
        std::cout<<n<<" "; 
    }

}
