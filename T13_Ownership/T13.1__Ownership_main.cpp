#include "T13.2_DrinkMachine.h"
#include "T13.6_Programmer.h"
#include <iostream>
#include <memory>

using namespace std;
//extern DrinkMachine sharedDrinkMachine;
//using namespace drinkMachine;

int main()
{
    cout << "Hello Ownership!\n";
    //auto sharedDrinkMachine = new DrinkMachine{};
    //auto sharedDrinkMachine = unique_ptr<DrinkMachine>(new DrinkMachine{});
    //auto sharedDrinkMachine = make_unique<DrinkMachine>();
    auto sharedDrinkMachine = make_shared<DrinkMachine>();
    
    //auto firstProgrammer = Programmer{ "Stephen", 50 };
    auto firstProgrammer = Programmer{ "Stephen", 100 };
    auto secondProgrammer = Programmer{ "John", 25 };
    //auto secondProgrammer = Programmer{ "John", 100 };
    //firstProgrammer.assign_drinkMachine(*sharedDrinkMachine.get());
    //secondProgrammer.assign_drinkMachine(*sharedDrinkMachine.get());
    firstProgrammer.assign_drinkMachine(sharedDrinkMachine);
    secondProgrammer.assign_drinkMachine(sharedDrinkMachine);
    
    while (true) {
        auto firstStatus = firstProgrammer.look_busy();
        auto secondStatus = secondProgrammer.look_busy();
        if (firstStatus == Programmer::QUIT && secondStatus == Programmer::QUIT) break;
    }
    
    //delete sharedDrinkMachine;
}