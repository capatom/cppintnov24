#include <iostream>
#include <utility> 

class MyArray {
public:
    // Default constructor (no tricks)
    MyArray(size_t size = 0)
        : size_(size), data_(size ? new int[size] : nullptr) {
        std::cout << "Default constructor called\n";
    }

    // Destructor (as normal)
    ~MyArray() {
        delete[] data_;
        std::cout << "Destructor called\n";
    }

    // Copy constructor (as you've seen before)
    MyArray(const MyArray& other)
        : size_(other.size_), data_(other.size_ ? new int[other.size_] : nullptr) {
        std::cout << "Copy constructor called\n";
        std::copy(other.data_, other.data_ + size_, data_);
    }

    // Move constructor (new, perhaps)
    MyArray(MyArray&& other) noexcept
        : size_(other.size_), data_(other.data_) {
        std::cout << "Move constructor called\n";
        other.size_ = 0;
        other.data_ = nullptr;
    }

    // Copy assignment operator (as you've seen before)
    MyArray& operator=(const MyArray& other) {
        std::cout << "Copy assignment operator called\n";
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            data_ = other.size_ ? new int[other.size_] : nullptr;
            std::copy(other.data_, other.data_ + size_, data_);
        }
        return *this;
    }

    // Move assignment operator (new, perhaps)
    MyArray& operator=(MyArray&& other) noexcept {
        std::cout << "Move assignment operator called\n";
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            data_ = other.data_;
            other.size_ = 0;
            other.data_ = nullptr;
        }
        return *this;
    }

private:
    size_t size_;
    int* data_;
};


// what does each line call - try to work it out before running :)
int main() {
    MyArray arr1(5);
    MyArray arr2 = arr1;
    MyArray arr3 = std::move(arr1);

    MyArray arr4;
    arr4 = arr2;
    arr4 = std::move(arr2);

    return 0;
}
