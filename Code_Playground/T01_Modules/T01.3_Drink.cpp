export module T01.Drink;
import std;
import <cassert>;

export namespace drink {
	class Drink;
}	

using namespace std; // not exported

namespace drink {
	class Drink {
	public:
		Drink(const char* name, int volume) : _name(name), _volume(volume) {}
		// queries
		string_view name() const { return _name; }
		int amount_left() const { return _volume; }
		// modifiers
		bool take_sip(int sip);
	private:
		string _name;
		int _volume;
	};

	bool Drink::take_sip(int sip) {
		assert(sip > 0);
		bool someLeft = _volume > 0;
		if (sip > _volume) _volume = 0;
		else _volume -= sip;
		return someLeft;
	}
}