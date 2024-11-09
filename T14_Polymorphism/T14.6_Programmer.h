#pragma once
#include "T14.2_DrinkMachine.h"
#include <string>
#include <string_view>
#include <vector>
#include <memory>
#include <expected>

class Programmer {
public:
	enum State { NO_MACHINE, NEED_DRINK, CAN_WRITE_CODE, EMPTY_CUP, MACHINE_NEEDS_REFILLING, WRITTEN_ENOUGH_CODE, GO_HOME, UNRECOVERABLE_ERROR, QUIT };
	Programmer(std::string_view name, int daily_output) : _name(name), _daily_quota_of_code(daily_output) {}
	// modifiers
	//void assign_drinkMachine(DrinkMachine& drinkMachine) { _shared_drinkMachine = &drinkMachine; }
	void assign_drinkMachine(std::shared_ptr<DrinkMachine> drinkMachine) { _shared_drinkMachine = std::move(drinkMachine); }
	//void drop_drinkMachine() { _shared_drinkMachine = nullptr; }
	void drop_drinkMachine() { _shared_drinkMachine.reset(); }
	State look_busy();
private:
	// modifiers
	std::expected<State, State> get_drink();
	std::expected<State, State> take_sip();
	std::expected<State, State> write_code();
	// Data
	State _state = NO_MACHINE;
	std::string _name;
	//DrinkMachine* _shared_drinkMachine = nullptr;
	std::shared_ptr<DrinkMachine> _shared_drinkMachine;
	std::unique_ptr<Drink> _drink;
	std::vector<std::string> _code_written;
	const int _daily_quota_of_code = 100;
};