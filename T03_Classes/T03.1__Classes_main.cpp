#include "T03.2_DrinkMachine.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello Classes!\n";
    auto myDrinkMachine = make_unique<DrinkMachine>();
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
    auto espresso = Recipe{ "Espresso", 20, 20, 0 };
    auto americano = espresso;
    auto emptyHopper = Hopper{};
    //auto copyHopper = emptyHopper;
    //americano = espresso;
}