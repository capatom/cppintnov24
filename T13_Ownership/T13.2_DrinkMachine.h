#pragma once
#include "T13.3_Drink.h"
#include "T13.4_Recipe.h"
#include "T13.5_Hopper.h"
#include <expected>
#include <vector>

// Interface
class DrinkMachine {
public:
	enum { SUGAR_DOSE = 10 };
	DrinkMachine();
	// queries
	bool can_make_drink(Recipe drinkRecipe) const;
	Recipe available_drinks() const { return _coffeeRecipe; }
	auto water_reserves() const { return _hoppers[Recipe::WATER].content(); }

	// modifiers
	std::expected<Drink, std::string> make_drink(Recipe drinkRecipe);
	void refill_hoppers();
private:
	Recipe _coffeeRecipe{ .name{"Latte"}, .ingredients{ 200, 20, 50} }; // designated array [0] = 1; in C but not C++
	std::vector<hopper::Hopper> _hoppers;
	hopper::Hopper _sugar;
};

//extern DrinkMachine sharedDrinkMachine;
//namespace drinkMachine {
//	//extern DrinkMachine sharedDrinkMachine;
//	//static DrinkMachine sharedDrinkMachine;
//	inline extern DrinkMachine sharedDrinkMachine{};
//}