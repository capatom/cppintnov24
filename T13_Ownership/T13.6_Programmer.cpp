#include "T13.6_Programmer.h"
#include <iostream>
#include <format>

using namespace std;

expected<Programmer::State, Programmer::State> Programmer::take_sip() {
    if (!_drink) return unexpected(EMPTY_CUP);
    else if (_drink->take_sip(100)) {
        cout << " Sipping " << _drink->name() << endl;
        return CAN_WRITE_CODE;
    }
    else {
        cout << "Cup empty\n";
    }
    return unexpected(EMPTY_CUP);
}

expected<Programmer::State, Programmer::State> Programmer::get_drink() {
    cout << "Get a drink\n";
    if (!_shared_drinkMachine) {
        cout << "No Drink Machine assigned.\n";
        return unexpected(NO_MACHINE);
    } else {
        auto myDrink = _shared_drinkMachine->make_drink(_shared_drinkMachine->available_drinks())
            .and_then([this](Drink drink)->expected<Drink, string> { _drink = make_unique<Drink>(drink); if (drink.amount_left() > 0) return drink; else return unexpected("Drink empty"); }) // called on OK. returns Drink
            .transform([](Drink drink) { cout << "\tMade Drink\n"; return drink; }); // called on OK. returns Drink

        if (myDrink.has_value()) return CAN_WRITE_CODE;
        else return unexpected(MACHINE_NEEDS_REFILLING);
    }
}

expected<Programmer::State, Programmer::State>  Programmer::write_code() {
    _code_written.push_back("Great code!");
    cout << format("... written {} lines of code...\n", _code_written.size());
    if (_code_written.size() < _daily_quota_of_code) return NEED_DRINK;
    else return unexpected(WRITTEN_ENOUGH_CODE);
}

Programmer::State Programmer::look_busy() {
    // lambdas
    auto goingHomeMsg = [this](bool enoughCode) -> string {
        auto msg = string{};
        if (enoughCode) {
            msg = format("written {} lines of code\n", _code_written.size());
        }
        else {
            msg = "Drink Machine needs refilling";
        }
        return format("\n{} Going home because {}", _name, msg);
    };

    // algorithm
    if (_state == QUIT) return QUIT;
    cout << _name << ": ";

    auto drinkOK = take_sip()
        .or_else([this](State err) -> expected<State, State> { return get_drink(); })
        .and_then([this](State ok) -> expected<State, State> { return write_code(); })
        .transform_error([goingHomeMsg,this](State err) {
            drop_drinkMachine();
            cout << goingHomeMsg(err == WRITTEN_ENOUGH_CODE) << endl;
            return QUIT; 
        });

    _state = drinkOK.has_value() ? drinkOK.value() : drinkOK.error();
    return _state;
}