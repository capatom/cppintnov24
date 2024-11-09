#pragma once
#include "T09.3_Drink.h"
#include "T09.4_Recipe.h"
#include "T09.5_Hopper.h"
#include <expected>

// Interface
class DrinkMachine {
public:
	DrinkMachine();
	// queries
	bool can_make_drink(Recipe drinkRecipe) const;
	Recipe available_drinks() const { return _coffeeRecipe; }
	auto water_reserves() const { return _waterHopper.content(); }

	// modifiers
	std::expected<Drink, std::string> make_drink(Recipe drinkRecipe);
private:
	Recipe _coffeeRecipe{ "Latte", 20, 200, 50 };
	hopper::Hopper _coffeeHopper{ "Coffee Beans", 500 };
	hopper::Hopper _waterHopper{ "Water",5000 };
	hopper::Hopper _milkHopper{ "Milk",1000 };
	hopper::Hopper _sugarHopper{"Sugar", 500};
};

extern DrinkMachine sharedDrinkMachine;