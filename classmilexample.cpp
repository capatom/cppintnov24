#include <iostream>
#include <string>

class Person {
public:
    // Constructor using Member Initializer List
    Person(const std::string& name, int age)
        : name_(name), age_(age) {
        // Constructor body can be empty - which is often preferred now...
    }

    void iam() const {
        std::cout << "Hello, my name is " << name_ << " and I am " << age_ << " years old." << std::endl;
    }

private:
    std::string name_;
    int age_;
};

int main() {
    Person Frank("Frank", 19);
    Frank.iam();

    return 0;
}
