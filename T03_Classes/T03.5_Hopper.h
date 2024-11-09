#pragma once 
#include <string>

class Hopper {
public:
	Hopper(const char* name, int capacity) : _name(name), _capacity(capacity) {}
	Hopper() = default;
	Hopper(const Hopper&) = delete;
	// queries
	std::string_view name() const { return _name; }
	int content() const { return _content; }
	int capacity() const { return _capacity; }
	// modifiers
	void refill(int amount);
	int remove(int amount);
private:
	const std::string _name;
	const int _capacity = 0;
	int _content = 0;
};
