#pragma once 
#include <string>
#include <array>

struct Recipe {
	enum MainIngredients { WATER, COFFEE, MILK, NO_OF_INGREDIENTS };
	const std::string name;
	std::array<const int, NO_OF_INGREDIENTS> ingredients;
};