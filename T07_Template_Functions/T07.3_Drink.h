#pragma once 
#include <string>
#include <string_view>

class Drink {
public:
	Drink() = default;
	Drink(const char* name, int volume)
		: _name(name)
		, _volume(volume)
	{}
	explicit Drink(int volume) : _volume(volume) {}
	// queries
	bool has_value() { return _name.size() > 0; }
	const char* error() { if (!has_value()) return "No-Name"; else return "OK"; }
	std::string_view name() const { return _name; }
	int amount_left() const { return _volume; }
	explicit operator bool() const { return amount_left() > 0; }
	// modifiers
	bool take_sip(int sip);
	Drink& operator+=(int sip) { _volume +=sip;  return *this; }
	Drink& operator+=(const Drink& rhs) { _volume += rhs.amount_left();  return *this; }
	Drink& operator-=(int sip) { take_sip(sip);  return *this; }
private:
	const std::string _name;
	int _volume = 0;
};
