export module T02.DrinkMachine:Drink;
import std;
import <cassert>;

export namespace drink {
	class Drink;
}	

using namespace std; // not exported

namespace drink {
	class Drink {
	public:
		Drink(const char* name, int voulme) : _name(name), _volume(voulme) {}
		// queries
		string_view name() const { return _name; }
		int amountLeft() const { return _volume; }
		// modifiers
		bool takeSip(int sip);
	private:
		string _name;
		int _volume;
	};

	bool Drink::takeSip(int sip) {
		assert(sip > 0);
		bool someLeft = _volume > 0;
		if (sip > _volume) _volume = 0;
		else _volume -= sip;
		return someLeft;
	}
}