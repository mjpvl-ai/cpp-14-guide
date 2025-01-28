#include <iostream> 
#include <vector> 
 
int main() { 
    std::vector<int> v1 = {1, 2, 3}; 
    std::vector<int> v2 = std::move(v1); // Move resources 
 
    std::cout << "v1 size: " << v1.size() << std::endl; // Empty 
    std::cout << "v2 size: " << v2.size() << std::endl; // 3 
 
    return 0; 
}
