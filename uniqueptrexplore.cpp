#include <iostream>
#include <memory>
#include <vector>

class Resource {
public:
    Resource(int value) : value_(value) {
        std::cout << "Resource acquired: " << value_ << '\n';
    }
    ~Resource() {
        std::cout << "Resource destroyed: " << value_ << '\n';
    }
    int getValue() const { return value_; }

private:
    int value_;
};

// Function that returns a unique_ptr to a new Resource
std::unique_ptr<Resource> createResource(int value) {
    return std::make_unique<Resource>(value);
}

// Function that takes ownership of a unique_ptr<Resource>
void processResource(std::unique_ptr<Resource> res) {
    if (res) {
        std::cout << "Processing Resource with value: " << res->getValue() << '\n';
    }
    // Resource will be destroyed when res goes out of scope
}

int main() {
    // Create a unique_ptr<Resource>
    std::unique_ptr<Resource> res1 = createResource(10);

    // Move ownership from res1 to res2
    std::unique_ptr<Resource> res2 = std::move(res1);

    if (!res1) {
        std::cout << "res1 is nullptr after move.\n";
    }

    if (res2) {
        std::cout << "res2 owns the Resource with value: " << res2->getValue() << '\n';
    }

    // Move res2 into the function, transferring ownership
    processResource(std::move(res2));

    if (!res2) {
        std::cout << "res2 is nullptr after being moved to processResource.\n";
    }

    // Create a vector to hold unique_ptr<Resource>
    std::vector<std::unique_ptr<Resource>> resources;
    resources.push_back(createResource(20));
    resources.push_back(createResource(30));

    // Access the resources in the vector
    for (const auto& res : resources) {
        std::cout << "Resource in vector with value: " << res->getValue() << '\n';
    }

    // Resources will be automatically destroyed when the vector goes out of scope
    return 0;
}
