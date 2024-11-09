#pragma once
#include "T07.3_Drink.h"
#include "T07.4_Recipe.h"
#include "T07.5_Hopper.h"

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
	hopper::Hopper _coffeeHopper{ "Coffee Beans", 500 };
	hopper::Hopper _waterHopper{ "Water",5000 };
	hopper::Hopper _milkHopper{ "Milk",1000 };
	hopper::Hopper _sugarHopper{"Sugar", 500};
};

extern DrinkMachine sharedDrinkMachine;