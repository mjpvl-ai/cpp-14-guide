#include <iostream> 
 
void print(int* p) { 
    if (p == nullptr) 
        std::cout << "Pointer is null\n"; 
    else 
        std::cout << "Pointer is not null\n"; 
} 
 
int main() { 
    int* ptr = nullptr; 
    print(ptr); 
 
    return 0; 
}
