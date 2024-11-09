#include "T07.2_DrinkMachine.h"
#include "Lib_Sum_Operators.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello Template_Classes!\n";
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

    {
        using namespace hopper;
        auto waterHopper = hopper::Hopper{ "Water", 100 };
        waterHopper.refill(waterHopper.capacity());
        cout << "waterHopper Post--:" << int(waterHopper--) << " Pre--: " << int(--waterHopper) << endl;
    }
    
    {
        auto drink = Drink(100);
        using namespace sum_Operators;
        cout << "drink Post--:" << drink--.amount_left() << " Pre--: " << (--drink).amount_left() << endl;
        auto combineDrinks = drink + Drink(50);
        auto topUp = combineDrinks + 25;
    }
}