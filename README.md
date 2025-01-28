# C++11 Features

## 1. Auto Keyword
Allows the compiler to deduce the type of a variable.

```cpp
#include <iostream>
#include <vector>

int main() {
    auto x = 10;           // int
    auto y = 3.14;         // double
    auto name = "John";    // const char*

    std::vector<int> vec = {1, 2, 3};
    for (auto v : vec) {   // Automatically deduces `int`
        std::cout << v << " ";
    }
    return 0;
}
```

## 2. Range-Based For Loop
Simplifies iteration over containers.

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    for (int num : numbers) {
        std::cout << num << " ";
    }
    return 0;
}
```

## 3. Lambda Expressions
Allows inline, anonymous functions.

```cpp
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
```

## 4. Strongly-Typed Enums (enum class)
Provides type safety for enums.

```cpp
#include <iostream>

enum class Color { Red, Green, Blue };  // Strongly-typed enum
enum class Size : char { Small = 'S', Medium = 'M', Large = 'L' }; // Enum with underlying type

int main() {
    Color c = Color::Red;  // Scoped access using Color::
    Size s = Size::Large;  // Scoped access using Size::

    // Printing values
    if (c == Color::Red) {
        std::cout << "Color is Red" << std::endl;
    }

    switch (s) {
        case Size::Small:
            std::cout << "Size is Small" << std::endl;
            break;
        case Size::Medium:
            std::cout << "Size is Medium" << std::endl;
            break;
        case Size::Large:
            std::cout << "Size is Large" << std::endl;
            break;
    }

    return 0;
}
```

## 5. Smart Pointers
Automatic memory management with `std::shared_ptr`, `std::unique_ptr`, and `std::weak_ptr`.

```cpp
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
```

## 6. Move Semantics
Efficient handling of temporary objects using `std::move`.

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = std::move(v1); // Move resources

    std::cout << "v1 size: " << v1.size() << std::endl; // Empty
    std::cout << "v2 size: " << v2.size() << std::endl; // 3

    return 0;
}
```

## 7. nullptr
Replaces `NULL` with a type-safe pointer literal.

```cpp
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
```

## 8. Threading Support
Introduces `std::thread` and related features.

```cpp
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
```

## 9. Variadic Templates
Allows functions to accept an arbitrary number of arguments.

```cpp
#include <iostream>

template <typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << std::endl; // Fold expression
}

int main() {
    print(1, 2, 3, "Hello", 4.5);

    return 0;
}
```

## 10. Type Aliases
Replaces `typedef` with `using`.

```cpp
#include <iostream>
#include <vector>

using IntVector = std::vector<int>;

int main() {
    IntVector vec = {1, 2, 3};
    for (int v : vec) {
        std::cout << v << " ";
    }

    return 0;
}
```

# C++14 Features

## 1. Generic Lambdas
Allows `auto` in lambda parameters.

```cpp
#include <iostream>

int main() {
    auto add = [](auto a, auto b) { return a + b; };
    std::cout << "Sum: " << add(5, 3.5) << std::endl;

    return 0;
}
```

## 2. Relaxed constexpr
`constexpr` functions can have more complex logic.

```cpp
#include <iostream>

constexpr int factorial(int n) {
    return n > 1 ? n * factorial(n - 1) : 1;
}

int main() {
    constexpr int result = factorial(5);
    std::cout << "Factorial: " << result << std::endl;

    return 0;
}
```

## 3. Return Type Deduction
Automatic deduction of function return types.

```cpp
#include <iostream>

auto add(int a, int b) {
    return a + b; // Compiler deduces `int`
}

int main() {
    std::cout << "Sum: " << add(5, 10) << std::endl;

    return 0;
}
```

## 4. Binary Literals
Use `0b` for binary numbers.

```cpp
#include <iostream>

int main() {
    int binary = 0b1101; // Binary for 13
    std::cout << "Binary: " << binary << std::endl;

    return 0;
}
```

## 5. Digit Separators
Use `'` to improve readability of large numbers.

```cpp
#include <iostream>

int main() {
    int million = 1'000'000;
    std::cout << "Million: " << million << std::endl;

    return 0;
}
```

## 6. std::make_unique
Simplifies creation of `std::unique_ptr`.

```cpp
#include <iostream>
#include <memory>

int main() {
    auto ptr = std::make_unique<int>(42);
    std::cout << "Value: " << *ptr << std::endl;

    return 0;
}
```

## 7. std::exchange
Replaces a value and returns the old value.

```cpp
#include <iostream>
#include <utility>

int main() {
    int x = 5;
    int old = std::exchange(x, 10);
    std::cout << "Old: " << old << ", New: " << x << std::endl;

    return 0;
}
```
