#include<vector>
#include<iostream>
#include<algorithm>
#include<ranges>
//using namespace std; 
struct Student
{
    /* data */

    std::string name; 

    int height; 
};

int main(){

    int a = 5, b = 10; 

    std::cout<<std::ranges::max(a,b); 

    std::vector<int> vec = {5,9,3,8,2};
    
    std::cout<<"\nThe max element of vector = ";
    
    std::cout<<std::ranges::max(vec)<<"\n"; 

    std::vector<Student>students = {{"Bob",35}, {"George",39}, {"Daniel",31}};

    auto oldest = std::ranges::max_element(students, {}, &Student::height); 

    std::cout<<"Oldest person is "<<oldest->name<<"\n"; 

}