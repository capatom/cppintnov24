#include "T01.2_MakeCoffee.h"
#include <iostream>

// Private Prototypes
const char* add_sugar();

// Implementation
void make_coffee() {
	std::cout << "Here's some coffee..." << add_sugar() << std::endl;
}

const char* add_sugar() {
	return "with sugar";
}

Drink make_drink(const char* drinkName) {
	return Drink{"Coffee", 200};
}