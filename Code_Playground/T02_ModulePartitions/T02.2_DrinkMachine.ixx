export module T02.DrinkMachine;
// Interface
export import :Recipe;
export import :Drink;
export import :Hopper;

export void MakeCoffee();

using namespace drink;

export class DrinkMachine {
public:
	DrinkMachine();
	// queries
	bool canMakeDrink(Recipe drinkRecipe) const;
	Recipe availableDrinks() const { return _coffee_recipe; }
	// modifiers
	expected<Drink, string> makeDrink(Recipe drinkRecipe);
private:
	Recipe _coffee_recipe{ "Latte", 20, 200, 50 };
	Hopper _coffeeHopper{ "Coffee Beans", 500 };
	Hopper _waterHopper{ "Water",5000 };
	Hopper _milkHopper{ "Milk",1000 };
	Hopper _sugarHopper{"Sugar", 500};
};

import std;
// Private Prototypes
const char* addSugar();

// Implementation

DrinkMachine::DrinkMachine() {
	_coffeeHopper.refill(_coffeeHopper.capacity());
	_waterHopper.refill(_waterHopper.capacity());
	_milkHopper.refill(_milkHopper.capacity());
	_sugarHopper.refill(_sugarHopper.capacity());
}

bool DrinkMachine::canMakeDrink(Recipe drinkRecipe) const {
	return _coffeeHopper >= drinkRecipe.beans_g
		&& _waterHopper >= drinkRecipe.water_ml
		&& _milkHopper >= drinkRecipe.milk_ml;
}

expected<Drink, string>  DrinkMachine::makeDrink(Recipe drinkRecipe) {
	if (canMakeDrink(drinkRecipe)) {
		_coffeeHopper.remove(drinkRecipe.beans_g);
		_waterHopper.remove(drinkRecipe.water_ml);
		_milkHopper.remove(drinkRecipe.milk_ml);
		return Drink{ drinkRecipe.name.c_str(), drinkRecipe.water_ml + drinkRecipe.milk_ml};
	}
	else return unexpected("Hoppers need filling");
}
