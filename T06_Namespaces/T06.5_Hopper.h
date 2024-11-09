#pragma once 
#include <string>
#include <string_view>

namespace hopper {
	class Hopper {
	public:
		Hopper(const char* name, int capacity) : _name(name), _capacity(capacity) {}
		// queries
		std::string_view name() const { return _name; }
		int content() const { return _content; }
		int capacity() const { return _capacity; }
		// modifiers
		void refill(int amount);
		int remove(int amount);
	private:
		friend auto operator <=> (const Hopper& lhs, int required);
		friend auto operator <=> (int required, const Hopper& rhs);
		friend auto operator == (const Hopper& lhs, int required);
		friend auto operator == (int required, const Hopper& rhs);

		const std::string _name;
		const int _capacity;
		int _content = 0;
	};

	inline auto operator <=> (const Hopper& lhs, int required) { return lhs._content <=> required; }
	inline auto operator <=> (int required, const Hopper& rhs ) { return required <=> rhs._content; }
	inline auto operator == (const Hopper& lhs, int required) { return lhs._content == required; }
	inline auto operator == (int required, const Hopper& rhs ) { return required == rhs._content; }
}