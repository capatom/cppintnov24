#pragma once 
#include <string>
#include <string_view>

    class Drink {
	public:
		Drink(const char* name, int volume) : _name(name), _volume(volume) {}
		// queries
		std::string_view name() const { return _name; }
		int amount_left() const { return _volume; }
		// modifiers
		bool take_sip(int sip);
	private:
		std::string _name;
		int _volume;
	};