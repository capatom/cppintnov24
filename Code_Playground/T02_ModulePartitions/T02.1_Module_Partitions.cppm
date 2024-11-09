import std;
import T02.DrinkMachine;

using namespace std;

int main()
{
    cout << "Hello Modules!\n";
    auto myDrinkMachine = make_unique<DrinkMachine>();
    while (true) {
        auto myDrink = sharedDrinkMachine.makeDrink(sharedDrinkMachine.availableDrinks());
        if (myDrink.has_value()) {
            cout << "Drinking " << myDrink->name() << endl;
            while (myDrink->takeSip(30)) {
                cout << " sip..";
            }
            cout << "\nFinished" << endl;
        }
        else {
            cout << myDrink.error() << endl;
            break;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
