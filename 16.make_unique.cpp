#include <iostream> 
#include <memory> 
 
int main() { 
    auto ptr = std::make_unique<int>(42); 
    std::cout << "Value: " << *ptr << std::endl; 
 
    return 0; 
} 
