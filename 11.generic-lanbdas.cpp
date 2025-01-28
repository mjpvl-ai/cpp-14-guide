#include <iostream> 
 
int main() { 
    auto add = [](auto a, auto b) { return a + b; }; 
    std::cout << "Sum: " << add(5, 3.5) << std::endl; 
 
    return 0; 
}
