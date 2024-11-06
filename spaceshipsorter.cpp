#include <iostream>
#include <algorithm>   // For std::ranges::sort
#include <compare>     // For the spaceship operator (<=>)
#include <ranges>
#include <vector>

// A custom class with the spaceship operator (<=>)
class Employee {
    public:
    std::string name;
    int age;

    // The three-way comparison operator (spaceship operator)
    auto operator<=>(const Employee&) const = default;  // Default implementation

    /* Optionally, you can provide a custom implementation if needed
    auto operator<=>(const Person& other) const {
        return age <=> other.age;  // Compare based on age
    */
};

// Helper function to print a vector of Employees
void print(const std::vector<Employee>& staff) {
    for (const auto& person : staff) {
        std::cout << person.name << " : " << person.age << " years" << std::endl;
    }
}

int main() {
    // Create a vector of Persons
    std::vector<Employee> staff = {
        {"Frank", 20},
        {"Phil", 8},
        {"Jess", 12},
    };

    // Sort using std::ranges::sort and the spaceship operator
    std::ranges::sort(staff);

    // Print sorted result
    std::cout << "Staff sorted by their ages:" << std::endl;
    print(staff);

    return 0;
}
