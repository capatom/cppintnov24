#include <iostream>
#include <algorithm>

template <typename T>
class Array {
public:
    // Constructor with MIL
    Array(std::size_t size)
        : size_(size), data_(new T[size_]) {}

    // Copy Constructor
    Array(const Array& other)
        : size_(other.size_), data_(new T[other.size_]) {
        for (std::size_t i = 0; i < size_; ++i)
            data_[i] = other.data_[i];
    }

    // Destructor
    ~Array() {
        delete[] data_;
    }

    // Assignment Operator
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            data_ = new T[size_];
            for (std::size_t i = 0; i < size_; ++i)
                data_[i] = other.data_[i];
        }
        return *this;
    }

    // Access Operator
    T& operator[](std::size_t index) {
        return data_[index];
    }

    // Const Access Operator
    const T& operator[](std::size_t index) const {
        return data_[index];
    }

    // Get Size
    std::size_t size() const {
        return size_;
    }

    T* begin() {
        return data_;
    }

    T* end() {
        return data_ + size_;
    }

    const T* begin() const {
        return data_;
    }

    const T* end() const {
       return data_ + size_;
    }

private:
    std::size_t size_;
    T* data_;
};

int main() {
    // Create an Array of integers programmatically
    Array<int> intArray(5);
    for (std::size_t i = 0; i < intArray.size(); ++i)
        intArray[i] = static_cast<int>(i) * 10;

    std::cout << "Integer Array: ";
    for (std::size_t i = 0; i < intArray.size(); ++i)
        std::cout << intArray[i] << " ";
    std::cout << std::endl;

    // Create an Array of doubles using assignment
    Array<double> doubleArray(3);
    doubleArray[0] = {1.21};
    doubleArray[1] = {2.31};
    doubleArray[2] = {3.41};

    std::cout << "Double Array: ";
    for (std::size_t i = 0; i < doubleArray.size(); ++i)
        std::cout << doubleArray[i] << " ";
    std::cout << std::endl;

    // Copying Arrays (testing assignment operator)
    Array<int> copiedArray = intArray;
    std::cout << "Copied Integer Array: ";
    for (std::size_t i = 0; i < copiedArray.size(); ++i)
        std::cout << copiedArray[i] << " ";
    std::cout << std::endl;

    // Testing standard algorithm using our begin and end explicitly
    std::cout << "Integer Array using std::for_each: ";
    std::for_each(intArray.begin(), intArray.end(), [](int& value) {
        std::cout << value << " ";
    });
    std::cout << std::endl;

    // Testing cleaner range-based iteration
    std::cout << "Integer Array using range-based for loop: ";
    for (auto& value : intArray) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
