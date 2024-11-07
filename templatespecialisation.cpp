#include <iostream>
#include <cmath>

// General template function
template <typename T>
bool isZero(const T& value) {
    std::cout << "General template version called for value: " << value << std::endl;
    return value == 0;
}

// Template specialization for float
template <>
bool isZero<float>(const float& value) {
    std::cout << "Float specialization called for value: " << value << std::endl;
    return std::fabs(value) < 1e-6f;
}

// Template specialization for double
template <>
bool isZero<double>(const double& value) {
    std::cout << "Double specialization called for value: " << value << std::endl;
    return std::fabs(value) < 1e-9;
}

int main() {
    int i{0};
    float f{1e-7f};
    double d{-1e-10};
    char c{0};
    long l{1000L};

    // Calling isZero with different types
    std::cout << std::boolalpha; // Print 'true' or 'false' instead of 1 or 0

    std::cout << "Is i zero? " << isZero(i) << std::endl;   // Calls general template
    std::cout << "Is f zero? " << isZero(f) << std::endl;   // Calls float specialization
    std::cout << "Is d zero? " << isZero(d) << std::endl;   // Calls double specialization
    std::cout << "Is c zero? " << isZero(c) << std::endl;   // Calls general template
    std::cout << "Is l zero? " << isZero(l) << std::endl;   // Calls general template

    // Revert back to default boolean output format
    std::cout << std::noboolalpha; // Now booleans will print as 1 or 0

    // Demonstrate that booleans now print as 1 or 0
    bool flag = true;
    std::cout << "Flag after noboolalpha: " << flag << std::endl;

    return 0;
}
