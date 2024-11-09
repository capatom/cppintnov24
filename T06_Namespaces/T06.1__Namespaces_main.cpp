#include "T06.2_DrinkMachine.h"
#include <iostream>

int main()
{
    std::cout << "Hello Namespaces!\n";

    while (true) {
        auto myDrink = sharedDrinkMachine.make_drink(sharedDrinkMachine.available_drinks());
        if (myDrink.has_value()) {
            std::cout << "Drinking " << myDrink.name() << std::endl;
            while (myDrink.take_sip(30)) {
                std::cout << " sip..";
            }
            std::cout << "\nFinished" << std::endl;
        }
        else {
            std::cout << myDrink.error() << std::endl;
            break;
        }
    }
}