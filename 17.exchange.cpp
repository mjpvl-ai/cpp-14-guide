#include <iostream> 
#include <utility> 
 
int main() { 
    int x = 5; 
    int old = std::exchange(x, 10); 
    std::cout << "Old: " << old << ", New: " << x << std::endl; 
 
    return 0; 
} 
