#include "T14.2_DrinkMachine.h"
#include "T14.6_Programmer.h"
#include "T14.7_Interruption.h"
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
    auto interruptions = vector<unique_ptr<Interruption>>();
    interruptions.push_back(make_unique<Need_A_Pee>("Stephen", Need_A_Pee::MALE));
    interruptions.push_back(make_unique<Dog_Eats_Neighbours_Cat>("John", "Jones"));
    interruptions.push_back(make_unique<Team_Meeting>("Stephen", "Pokey-3"));
   
    auto next_interruption = 0;

    while (true) {
        auto firstStatus = firstProgrammer.look_busy();
        auto secondStatus = secondProgrammer.look_busy();
        interruptions[next_interruption]->execute();
        ++next_interruption;
        next_interruption = next_interruption % interruptions.size();
        if (firstStatus == Programmer::QUIT && secondStatus == Programmer::QUIT) break;
    }
    
    //delete sharedDrinkMachine;
}