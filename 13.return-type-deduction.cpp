#include <iostream> 
 
auto add(int a, int b) { 
    return a + b; // Compiler deduces `int` 
} 
 
int main() { 
    std::cout << "Sum: " << add(5, 10) << std::endl; 
 
    return 0; 
}
