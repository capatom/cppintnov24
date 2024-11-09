export module T01.MakeCoffee;
import T01.Drink;
import std;

// Interface
export void make_coffee();
export drink::Drink make_drink(const char* drinkName);

// Private Prototypes
const char* add_sugar();

// Implementation
void make_coffee() {
	std::cout << "Here's some coffee..." << add_sugar() << std::endl;
}

const char* add_sugar() {
	return "with sugar";
}

drink::Drink make_drink(const char* drinkName) {
	return drink::Drink{"Coffee", 200};
}