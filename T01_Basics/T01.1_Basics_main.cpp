#include <iostream>
#include "T01.2_MakeCoffee.h"

int main(int argc, char* argv[], char* envp[])
{
    std::cout << "Hello Basics!\n";
    make_coffee();
    auto myDrink = make_drink("Coffee");
    std::cout << "Drinking " << myDrink.name() << std::endl;
    while (myDrink.take_sip(10)) {
        std::cout << " sip..";
    }
    std::cout << "\nFinished" << std::endl;
}