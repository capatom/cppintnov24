#include <iostream>

struct PaddedStruct {
    char   c; // 1 byte
    int    i; // 4 bytes
    float  f; // 4 bytes
};

#pragma pack(push, 1)
struct PackedStruct {
    char   c; // 1 byte
    int    i; // 4 bytes
    float  f; // 4 bytes
};
#pragma pack(pop)

int main() {
    std::cout << "Size of PaddedStruct: " << sizeof(PaddedStruct) << " bytes\n";
    std::cout << "Size of PackedStruct: " << sizeof(PackedStruct) << " bytes\n";
    return 0;
}
