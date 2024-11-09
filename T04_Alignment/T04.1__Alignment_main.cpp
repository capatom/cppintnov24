#include "T04.2_DrinkMachine.h"
#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
    cout << "Hello Alignment!\n";
    while (true) {
        auto myDrink = sharedDrinkMachine.make_drink(sharedDrinkMachine.available_drinks());
        if (myDrink.has_value()) {
            cout << "Drinking " << myDrink.name() << endl;
            while (myDrink.take_sip(30)) {
                cout << " sip..";
            }
            cout << "\nFinished" << endl;
        }
        else {
            cout << myDrink.error() << endl;
            break;
        }
    }

    cout << endl;
    cout << "String size:" << sizeof(Recipe::name) << endl;
    cout << "ingredients size:" << 3 * sizeof(Recipe::beans_g) << endl;
    cout << "Recipe size:" << sizeof(Recipe) << endl;
    cout << "Recipe Padding:" << sizeof(Recipe) - sizeof(Recipe::name) - 3 * sizeof(Recipe::beans_g) << endl << endl;

    cout << "int8_t  Alignment: " << alignof(int8_t) << endl;
    cout << "int16_t Alignment: " << alignof(int16_t) << endl;
    cout << "int32_t Alignment: " << alignof(int32_t) << endl;
    cout << "int64_t Alignment: " << alignof(int64_t) << endl;
    cout << "string  Alignment: " << alignof(string) << " Size: " << sizeof(string) << endl << endl;
    
    struct all_chars {int8_t a,b,c; };
    all_chars arr_of_3chars[3];    
    cout << "all_chars   Size: " << sizeof(all_chars) << " arr_of_3chars Size:" << sizeof(arr_of_3chars) << endl;
    
    struct mixedInts   { int8_t c; int64_t l; int8_t c2; int16_t s; int32_t i; };
    struct orderedInts { int64_t l; int32_t i; int16_t s; int8_t c; int8_t c2; };
    struct ordered_9Chars_ { int64_t l; int32_t i; int16_t s; int8_t c; };

    auto noOfBytes = sizeof(int64_t) + sizeof(int32_t) + sizeof(int16_t) + 2 * sizeof(int8_t);
     cout << "mixedInts   Size: " << sizeof(mixedInts) << " Padding:" << sizeof(mixedInts) - noOfBytes << endl;
    cout << "orderedInts Size: " << sizeof(orderedInts) << " Padding:" << sizeof(orderedInts) - noOfBytes << endl;
    cout << "ordered_9Chars Size:" << sizeof(ordered_9Chars_) << " Padding:" << sizeof(ordered_9Chars_) - (noOfBytes - 1) << endl;
}