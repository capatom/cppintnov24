#include <iostream>
#include <string>

void printValue(const std::string& str) {
    std::cout << "L-value reference: " << str << std::endl;
}

void printValue(std::string&& str) {
    std::cout << "R-value reference: " << str << std::endl;
}

int main() {
    std::string s = "Hello";
    printValue(s);           // Which will version will it call and why?
    printValue("World");     // "
    printValue(s + "!");     // "
    return 0;
}
