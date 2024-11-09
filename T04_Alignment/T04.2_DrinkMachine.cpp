#include "T04.2_DrinkMachine.h"

DrinkMachine sharedDrinkMachine{};

// Private Free Functions
const char* add_sugar() {
	return " with sugar";
}

// Implementation

DrinkMachine::DrinkMachine() {
	_coffeeHopper.refill(_coffeeHopper.capacity());
	_waterHopper.refill(_waterHopper.capacity());
	_milkHopper.refill(_milkHopper.capacity());
	_sugarHopper.refill(_sugarHopper.capacity());
}

bool DrinkMachine::can_make_drink(Recipe drinkRecipe) const {
	return _coffeeHopper.content() >= drinkRecipe.beans_g
		&& _waterHopper.content() >= drinkRecipe.water_ml
		&& _milkHopper.content() >= drinkRecipe.milk_ml;
}

Drink  DrinkMachine::make_drink(Recipe drinkRecipe) {
	if (can_make_drink(drinkRecipe)) {
		_coffeeHopper.remove(drinkRecipe.beans_g);
		_waterHopper.remove(drinkRecipe.water_ml);
		_milkHopper.remove(drinkRecipe.milk_ml);
		return Drink{ (drinkRecipe.name + add_sugar()).c_str(), drinkRecipe.water_ml + drinkRecipe.milk_ml };
	}
	else return Drink{};
}