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
