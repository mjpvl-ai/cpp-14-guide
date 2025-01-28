#include <iostream> 
#include <vector> 
 
int main() { 
    auto x = 10;           // int 
    auto y = 3.14;         // double 
    auto name = "John";    // const char* 
 
    std::vector<int> vec = {1, 2, 3}; 
    for (auto v : vec) {   // Automatically deduces int 
        std::cout << v << " "; 
    } 
    std::cout <<"\n";
    return 0; 
}
