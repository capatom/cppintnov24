#include "T05.2_DrinkMachine.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello Classes!\n";
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

    auto compareHoppers = Hopper{ "",100 } > 50;
    compareHoppers = 50 < Hopper{ "",100 };
    //compareHoppers = Hopper{ "",100 } > Hopper{"", 50};

    auto myDrink = Drink{ 120 };
    //Drink yourDrink = 200;

    auto lotsLeft = bool(myDrink);
    //bool someLeft = myDrink;
    if (myDrink); // compiler casts to bool
}