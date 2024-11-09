#include "T08.2_DrinkMachine.h"
#include "T08.6_Programmer.h"
#include <iostream>

int main()
{
    std::cout << "Hello Lambdas!\n";
    auto firstProgrammer = Programmer{ "Stephen", 50 };
    //auto firstProgrammer = Programmer{ 100 };
    firstProgrammer.assign_drinkMachine(sharedDrinkMachine);
    auto secondProgrammer = Programmer{ "John", 25 };
    //auto secondProgrammer = Programmer{ 100 };
    firstProgrammer.assign_drinkMachine(sharedDrinkMachine);
    secondProgrammer.assign_drinkMachine(sharedDrinkMachine);
    while (true) {
        auto firstStatus = firstProgrammer.look_busy();
        auto secondStatus = secondProgrammer.look_busy();
        if (firstStatus == Programmer::QUIT && secondStatus == Programmer::QUIT) break;
    }
}