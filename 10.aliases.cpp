#include <iostream> 
#include <vector> 
 
using IntVector = std::vector<int>; 
 
int main() { 
    IntVector vec = {1, 2, 3}; 
    for (int v : vec) { 
        std::cout << v << " "; 
    } 
 
    return 0; 
} 
 
