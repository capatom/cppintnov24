#include <iostream>
#include <typeinfo>

int main() {
    auto x = 42;           // x is deduced as int
    auto y = 3.14;         // y is deduced as double
    auto z = "Hello";      // z is deduced as const char*

    std::cout << "Type of x: " << typeid(x).name() << std::endl;
    std::cout << "Type of y: " << typeid(y).name() << std::endl;
    std::cout << "Type of z: " << typeid(z).name() << std::endl;

    return 0;
}
