#include "T14.2_DrinkMachine.h"
#include <ranges>

//static DrinkMachine sharedDrinkMachine{};
//namespace /*drinkMachine*/ {
//	//extern DrinkMachine sharedDrinkMachine;
//	//static DrinkMachine sharedDrinkMachine;
//	inline extern DrinkMachine sharedDrinkMachine{};
//}

// Private Free Functions
namespace {
	const char* add_sugar() {
		return " with sugar";
	}
}

// Implementation

DrinkMachine::DrinkMachine()
	: _hoppers{ 				// vector
		{ "Water", 5000 }
		, { "Coffee Beans", 500 }
		, { "Milk", 1000 }
	}
	, _sugar{ "Sugar", 500 }
{
	refill_hoppers();
}

bool DrinkMachine::can_make_drink(Recipe drinkRecipe) const {
	for (auto ingredient_index : std::views::iota(0, Recipe::NO_OF_INGREDIENTS)) {
		if (_hoppers[ingredient_index] < drinkRecipe.ingredients[ingredient_index]) return false;
	}
	if (_sugar.content() < SUGAR_DOSE) return false;
	return true;
}

std::expected<Drink, std::string>  DrinkMachine::make_drink(Recipe drinkRecipe) {
	if (can_make_drink(drinkRecipe)) {
		for (auto ingredient_index : std::views::iota(0, Recipe::NO_OF_INGREDIENTS)) {
			_hoppers[ingredient_index] -= drinkRecipe.ingredients[ingredient_index];
		}
		_sugar -= SUGAR_DOSE;
		return Drink{ (drinkRecipe.name + add_sugar()).c_str(), drinkRecipe.ingredients[Recipe::WATER] + drinkRecipe.ingredients[Recipe::MILK] };
	}
	else return std::unexpected("Hoppers need filling");
}

void DrinkMachine::refill_hoppers() {
	for (auto& hopper : _hoppers) {
		hopper.refill(hopper.capacity());
	}
	_sugar.refill(_sugar.capacity());
}