#include <iostream>
#include <memory>   // For std::shared_ptr
#include <string>

// Custom class with just a single data member
class Person {
public:
    // our constructor
    Person(const std::string& name) : name_(name) {
        std::cout << "Person '" << name_ << "' created.\n";
    }

    // our destructor
    ~Person() {
        std::cout << "Person '" << name_ << "' destroyed.\n";
    }

    // method to display the person's name
    void display() const {
        std::cout << "Person's name: " << name_ << "\n";
    }

private:
    std::string name_;
};

// Function that takes a shared_ptr and displays the person's name
void printPerson(std::shared_ptr<Person> p) {
    std::cout << "Inside printPerson function.\n";
    p->display();
    std::cout << "Reference count inside printPerson: " << p.use_count() << "\n";
}

int main() {
    // Creates a shared_ptr to a new Person object
    std::shared_ptr<Person> personPtr1 = std::make_shared<Person>("Alice");

    std::cout << "Reference count after creation: " << personPtr1.use_count() << "\n\n";

    {
        // Create another shared_ptr that shares ownership with personPtr1
        std::shared_ptr<Person> personPtr2 = personPtr1;
        std::cout << "Reference count after personPtr2 is created: " << personPtr1.use_count() << "\n";

        // Use the shared_ptr
        personPtr2->display();

        // Pass shared_ptr to a function
        printPerson(personPtr2);

        std::cout << "Reference count after passing to printPerson: " << personPtr1.use_count() << "\n\n";
    } // personPtr2 goes out of scope here

    std::cout << "Reference count after personPtr2 is out of scope: " << personPtr1.use_count() << "\n\n";

    // Reset personPtr1, releasing ownership of the Person object
    personPtr1.reset();
    std::cout << "Reference count after resetting personPtr1: " << personPtr1.use_count() << "\n";

    return 0;
}
