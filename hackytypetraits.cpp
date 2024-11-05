#include <iostream>
#include <type_traits>

template<typename T>
void printType(const T&) {
    if (std::is_same<T, int>::value) {
        std::cout << "Type is int" << std::endl;
    } else if (std::is_same<T, double>::value) {
        std::cout << "Type is double" << std::endl;
    } else if (std::is_same<T, const char*>::value) {
        std::cout << "Type is const char*" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

int main() {
    auto x = 42;
    auto y = 3.14;
    auto z = "Hello";

    // call the templated function which will then compare the T passed
    printType(x); // Output: Type is int
    printType(y); // Output: Type is double
    printType(z); // Output: Type is const char*

    return 0;
}
