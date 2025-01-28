#include <iostream> 
#include <vector> 
#include <algorithm>
 
int main() { 
    auto multiply = [](int a, int b) { return a * b; }; 
    std::cout << "Product: " << multiply(4, 5) << std::endl; 
 
    std::vector<int> nums = {1, 2, 3, 4}; 
    int sum = 0; 
    std::for_each(nums.begin(), nums.end(), [&sum](int n) { sum += n; }); 
    std::cout << "Sum: " << sum << std::endl; 
 
    return 0; 
}
