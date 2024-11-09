#include "T11.2_DrinkMachine.h"
#include "T11.6_Programmer.h"
#include <iostream>

using namespace std;

#define TEST_STRING

#ifndef TEST_STRING
 int main()
 {
     std::cout << "Hello Errors!\n";
    //auto firstProgrammer = Programmer{ "Stephen", 50 };
    auto firstProgrammer = Programmer{ "Stephen", 100 };
    firstProgrammer.assign_drinkMachine(sharedDrinkMachine);
    auto secondProgrammer = Programmer{ "John", 25 };
    //auto secondProgrammer = Programmer{ "John", 100 };
    firstProgrammer.assign_drinkMachine(sharedDrinkMachine);
    secondProgrammer.assign_drinkMachine(sharedDrinkMachine);
    while (true) {
        auto firstStatus = firstProgrammer.look_busy();
        auto secondStatus = secondProgrammer.look_busy();
        if (firstStatus == Programmer::QUIT && secondStatus == Programmer::QUIT) break;
    }
 }

#else

#include "Lib_String.h"
#include <vector>
#include <algorithm>
#include <type_traits>

int main()
{
    cout << "Hello Move_Semantics!\n";

    cout << "\nCreate myV\n";
    auto myV = vector<String>();
    myV.reserve(1);
    cout << "myV.0 Capacity: " << myV.capacity() << endl << endl;

    myV.push_back("Hello");
    cout << "myV.1 Capacity: " << myV.capacity() << endl << endl;

    myV.push_back("Move_Semantics!");
    cout << "myV.2 Capacity: " << myV.capacity() << endl << endl;

    cout << "Swap\n";
    std::swap(myV[0], myV[1]);
    cout << endl;

    cout << "\nstring_swap\n";
    string_swap(myV[0], myV[1]);

    for (const auto& val : myV) {
        cout << val << ' ';
    }

    static_assert(
        std::is_nothrow_move_constructible<String>::value
        && std::is_nothrow_move_assignable<String>::value,
        "Class not nothrow movable");

    cout << "\nDone\n\n";
}
#endif
