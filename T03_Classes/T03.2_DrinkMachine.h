#pragma once
#include "T03.3_Drink.h"
#include "T03.4_Recipe.h"
#include "T03.5_Hopper.h"

// Interface
class DrinkMachine {
public:
	DrinkMachine();
	// queries
	bool can_make_drink(Recipe drinkRecipe) const;
	Recipe available_drinks() const { return _coffeeRecipe; }
	// modifiers
	Drink make_drink(Recipe drinkRecipe);
private:
	Recipe _coffeeRecipe{ "Latte", 20, 200, 50 };
	Hopper _coffeeHopper{ "Coffee Beans", 500 };
	Hopper _waterHopper{ "Water",5000 };
	Hopper _milkHopper{ "Milk",1000 };
	Hopper _sugarHopper{"Sugar", 500};
};

extern DrinkMachine sharedDrinkMachine;