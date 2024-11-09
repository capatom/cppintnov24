#include "T12.2_DrinkMachine.h"
#include "T12.6_Programmer.h"
#include <iostream>

using namespace std;
//extern DrinkMachine sharedDrinkMachine;
using namespace drinkMachine;

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