#include <iostream>
#include <vector>
#include <string>
#include <memory>        // For smart pointers
#include <unordered_map> // For hash maps
#include <algorithm>     // For std::for_each
#include <initializer_list> // For initializer lists
#include <chrono>        // For chrono
#include <ctime>         // For std::ctime

// Feature 1: Strongly-Typed Enums
enum class Genre { Fiction, NonFiction, SciFi, Fantasy };

// Feature 3: Override and Final
class BaseLibrary {
public:
    virtual void showDetails() const {
        std::cout << "Base Library Details" << std::endl;
    }
    virtual ~BaseLibrary() = default; // Defaulted functions (Feature 6)
};

class Library final : public BaseLibrary { // 'final' prevents inheritance
private:
    // Feature 12: std::unordered_map (hash table)
    std::unordered_map<int, std::string> books;

    // Feature 10: Smart Pointers
    std::vector<std::unique_ptr<std::string>> authors;

public:
    // Feature 4: Default and Deleted Functions
    Library() = default;
    Library(const Library&) = delete;             // Prevent copying
    Library& operator=(const Library&) = delete;  // Prevent assignment

    // Feature 8: Variadic Templates and Overloading
    void addBooks(std::initializer_list<std::string> bookList) {
        int id = books.size() + 1;
        for (const auto& book : bookList) {
            books[id++] = book;
        }
    }

    template <typename... Args>
    void addBooks(Args... args) {
        int id = books.size() + 1;
        (..., books.emplace(id++, args)); // Fold expression (C++17)
    }

    // Feature 2: auto and decltype
    auto getBookTitle(int id) -> decltype(books.find(id)->second) {
        return books.at(id);
    }

    void addAuthor(const std::string& author) {
        // Feature 10: Smart Pointers
        authors.emplace_back(std::make_unique<std::string>(author));
    }

    void showAuthors() const {
        std::cout << "Authors:\n";
        for (const auto& author : authors) { // Feature 5: Range-based for loops
            std::cout << " - " << *author << std::endl;
        }
    }

    // Feature 7: Lambda Expressions
    void showBooks() const {
        std::for_each(books.begin(), books.end(), [](const auto& pair) {
            std::cout << "Book ID: " << pair.first << ", Title: " << pair.second << std::endl;
        });
    }

    // Feature 11: Move Semantics
    void addMovedBook(std::string&& title) {
        int id = books.size() + 1;
        books[id] = std::move(title); // Move instead of copying
    }

    // Feature 13: std::chrono
    void printCurrentTime() const {
        using namespace std::chrono;
        auto now = system_clock::now();
        auto time = system_clock::to_time_t(now);
        std::cout << "Current Time: " << std::ctime(&time);
    }

    // Feature 17: User-Defined Literals
    void setGenre(Genre genre) {
        std::cout << "Genre set to ";
        switch (genre) {
            case Genre::Fiction:    std::cout << "Fiction\n"; break;
            case Genre::NonFiction: std::cout << "NonFiction\n"; break;
            case Genre::SciFi:      std::cout << "SciFi\n"; break;
            case Genre::Fantasy:    std::cout << "Fantasy\n"; break;
        }
    }
};

int main() {
    // Feature 9: Initializer Lists
    Library library;
    library.addBooks({"C++ Primer", "Effective Modern C++", "Clean Code"});

    library.addAuthor("Bjarne Stroustrup");
    library.addAuthor("Scott Meyers");

    library.addMovedBook("The Pragmatic Programmer"); // Move semantics
    library.showBooks();
    library.showAuthors();

    library.setGenre(Genre::SciFi); // Strongly-Typed Enums

    // Feature 13: std::chrono
    library.printCurrentTime();

    // Feature 15: constexpr
    constexpr int maxBooks = 1000;
    std::cout << "Max books allowed: " << maxBooks << std::endl;

    // Feature 16: std::tuple and Structured Bindings
    auto bookInfo = std::make_tuple(1, "C++ Programming", Genre::Fiction);
    auto [id, title, genre] = bookInfo; // Structured bindings
    std::cout << "Book Info -> ID: " << id << ", Title: " << title << std::endl;

    return 0;
}
