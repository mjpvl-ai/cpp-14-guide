#include <iostream> 
#include <memory> 
 
class MyClass { 
public: 
    MyClass() { std::cout << "Object created\n"; } 
    ~MyClass() { std::cout << "Object destroyed\n"; } 
}; 
 
int main() { 
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>(); 
    std::unique_ptr<MyClass> ptr2 = std::make_unique<MyClass>(); 
 
    return 0; // Objects are automatically destroyed 
}
