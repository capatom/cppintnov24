#pragma once
#include <initializer_list>
#include <iostream>
#include<cstring>

class String {
public:
    String() = default;
    String(const char*);
    String(const String&);
    String(String&&) noexcept;
    String& operator=(const String&);
    String& operator=(String&&) noexcept;
    // queries
    const char* c_str() const { return _body; }
    ~String() { deallocate(); }
private:
    // modifiers
    void reserve(size_t capacity);
    void deallocate();
    char* _body = nullptr;
    size_t _capacity = 0;
    size_t _size = 0;
};

inline std::ostream& operator<<(std::ostream& lhs, const String& rhs) {
    return lhs << rhs.c_str();
}

inline void string_swap(String& lhs, String& rhs) {
    auto temp = std::move(lhs);
    lhs = std::move(rhs);
    rhs = std::move(temp);
}

inline void String::reserve(size_t capacity) {
    std::cout << "String allocation... " << capacity << std::endl;
    auto temp_body = new char[capacity]; // exception-safe allocate before delete
    deallocate();
    _body = temp_body;
    _capacity = capacity;
}

inline String::String(const char* ini) {
    _size = strlen(ini) + 1;
    if (_size > _capacity) reserve(_size);
    strncpy(_body, ini, _size);
}

inline String::String(const String& rhs) {
    std::cout << "Copy of " << rhs << "...\n";
    _size = rhs._size;
    if (_size > _capacity) reserve(_size);
    strncpy(_body, rhs._body, _size);
}

//String& String::operator=(String rhs) { // ambiguous with operator=(String&& rhs)
inline String& String::operator=(const String& rhs_ref) {
    std::cout << "\nCopy-assignment from " << rhs_ref << "...\n";
    auto rhs = rhs_ref; // copy before delete is exception-safe
    std::swap(_size, rhs._size);
    std::swap(_capacity, rhs._capacity);
    std::swap(_body, rhs._body); // rhs destruction deallocates old _body
    return *this;
}

inline String::String(String&& rhs) noexcept {
    _size = rhs._size;
    _capacity = rhs._capacity;
    _body = rhs._body;
    rhs._body = nullptr;
    rhs._size = 0;
    rhs._capacity = 0;
    std::cout << _body << " moved" << std::endl;
}

inline String& String::operator=(String&& rhs) noexcept {
    std::swap(_size, rhs._size);
    std::swap(_capacity, rhs._capacity);
    std::swap(_body, rhs._body);
    std::cout << _body << " moved-assigned" << std::endl;
    return *this;
}

inline void String::deallocate() {
    if (_capacity > 0) {
        std::cout << _body << " deleted" << std::endl;
    }
    delete[] _body;
    _body = nullptr;
    _capacity = 0;
}
