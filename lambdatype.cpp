#include <iostream>
#include <functional>

int main() {
    // A lambda expression
    auto lambda = [](int x) { return x * x; };

    // A function pointer
    int (*funcPtr)(int) = [](int x) { return x + x; };

    // std::function erases the concrete types of lambda and funcPtr, but specifies the shared interface int->f()->int
    std::function<int(int)> func;

    func = lambda;
    std::cout << "Lambda result: " << func(5) << std::endl; // Output: 25

    func = funcPtr;
    std::cout << "Function pointer result: " << func(5) << std::endl; // Output: 10

    return 0;
}
