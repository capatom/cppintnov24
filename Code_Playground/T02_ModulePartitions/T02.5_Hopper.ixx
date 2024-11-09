export module T02.DrinkMachine:Hopper;
import std;
import <cassert>;

using namespace std;

export class Hopper {
public:
	Hopper(const char* name, int capacity) : _name(name), _capacity(capacity) {}
	// queries
	string_view name() const { return _name; }
	int contect() const { return _content; }
	int capacity() const { return _capacity; }
	// modifiers
	void refill(int amount);
	int remove(int amount);
private:
	friend auto operator <=> (const Hopper& lhs, int required);
	friend auto operator <=> (int required, const Hopper& rhs);
	friend auto operator == (const Hopper& lhs, int required);
	friend auto operator == (int required, const Hopper& rhs);

	string _name;
	int _capacity;
	int _content = 0;
};


export auto operator <=> (const Hopper& lhs, int required) { return lhs._content <=> required; }
export auto operator <=> (int required, const Hopper& rhs ) { return required <=> rhs._content; }
export auto operator == (const Hopper& lhs, int required) { return lhs._content == required; }
export auto operator == (int required, const Hopper& rhs ) { return required == rhs._content; }

void Hopper::refill(int amount) {
	assert(amount > 0);
	_content += amount;
	if (_content > _capacity) _content = _capacity;
}

int Hopper::remove(int amount) {
	assert(amount >= 0);
	if (amount > _content) amount = _content;
	_content -= amount;
	return amount;
}
