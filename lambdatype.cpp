#include <iostream>
#include <typeinfo>

int main() {
    int x = 10;
    // Lambda function capturing 'x' by copy - () removed for comparison, as no args...better?
    auto squareIt = [x] {
        return x * x;
    };
    // Call the lambda function, store returned value
    int result = squareIt();

    // Print the result
    std::cout << "Result: " << result << std::endl;

    // Print the original value of 'x' (unchanged)
    std::cout << "Original value of x: " << x << std::endl;

    // Attempting to print the type of squareIt
    std::cout << "Type of squareIt: " << typeid(squareIt).name() << std::endl;
    return 0;
}
