#include <iostream>

struct MyType {
    MyType() = default;

    // Copy constructor
    MyType(const MyType&) {
        std::cout << "Copy constructor called\n";
    }

    // Copy assignment operator
    MyType& operator=(const MyType&) {
        std::cout << "Copy assignment called\n";
        return *this;
    }
};

int main() {
    MyType original;

    // Using auto (copy)
    auto copy = original; // Invokes copy constructor
    // Output: "Copy constructor called"

    // Modifying the copy
    copy = original; // Invokes copy assignment operator
    // Output: "Copy assignment called"

    // Using auto& (reference)
    auto& ref = original; // No copy; ref is a reference to original

    // Modifying through ref
    // (No output because no copy occurs)
    ref = original; // Still no copy; self-assignment

    // Using const auto& (const reference)
    const auto& constRef = original; // No copy; constRef is a const reference
    // Cannot modify through constRef

    return 0;
}
