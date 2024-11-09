#pragma once
#include "T08.2_DrinkMachine.h"
#include <string>

class Programmer {
public:
	enum State { NO_MACHINE, NEED_DRINK, CAN_WRITE_CODE, EMPTY_CUP, MACHINE_NEEDS_REFILLING, WRITTEN_ENOUGH_CODE, GO_HOME, UNRECOVERABLE_ERROR, QUIT};
	Programmer(std::string_view name, int daily_output) : _name(name), _daily_quota_of_code(daily_output) {}
	// queries
	State drinkMachine();
	// modifiers
	void assign_drinkMachine(DrinkMachine& drinkMachine) { _shared_drinkMachine = &drinkMachine; }
	State drop_drinkMachine() { _shared_drinkMachine = nullptr; }
	State get_started();
	State look_busy();
private:
	// modifiers
	State get_drink(std::string err);
	State take_sip();
	State write_code();
	// Data
	State _state = NO_MACHINE;
	std::string _name;
	DrinkMachine* _shared_drinkMachine = nullptr;
	Drink _drink;
	int _code_written;
	const int _daily_quota_of_code = 100;
};