#include <iostream> 
#include <thread> 
 
void printMessage() { 
    std::cout << "Hello from thread!" << std::endl; 
} 
 
int main() { 
    std::thread t(printMessage); 
    t.join(); // Wait for the thread to complete 
 
    return 0; 
} 
 
