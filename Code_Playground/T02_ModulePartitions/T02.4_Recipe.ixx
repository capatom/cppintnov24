export module T02.DrinkMachine:Recipe;
import std;

using namespace std;

export struct Recipe {
	string name;
	int beans_g;
	int water_ml;
	int milk_ml;
};