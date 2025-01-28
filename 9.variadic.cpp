#include <iostream> 
 
template <typename... Args> 
void print(Args... args) { 
    (std::cout << ... << args) << std::endl; // Fold expression 
} 
 
int main() { 
    print(1, 2, 3, "Hello", 4.5); 
 
    return 0; 
}
