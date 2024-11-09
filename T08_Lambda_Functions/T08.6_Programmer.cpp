#include "T08.6_Programmer.h"
#include <iostream>
#include <format>

using namespace std;

Programmer::State Programmer::take_sip() {
    if (_drink.take_sip(100)) {
        cout << " Sipping " << _drink.name() << endl;
        return CAN_WRITE_CODE;
    }
    cout << "Cup empty\n";
    return EMPTY_CUP;
}

Programmer::State Programmer::get_drink(string msg) {
    cout << msg << endl;
    _drink = _shared_drinkMachine->make_drink(_shared_drinkMachine->available_drinks());
    if (!_drink) {
        return MACHINE_NEEDS_REFILLING;
    }
    else {
        cout << "\tMade Drink\n"; 
        return NEED_DRINK;
    }
}

Programmer::State Programmer::drinkMachine() {
    if (_shared_drinkMachine) {
        if (_shared_drinkMachine->can_make_drink(_shared_drinkMachine->available_drinks())) {
            cout << "Machine OK\n";
            return EMPTY_CUP;
        } else {
            return MACHINE_NEEDS_REFILLING;
        }
    } else {
        return NO_MACHINE; 
    }
}

Programmer::State Programmer::write_code() {
    ++_code_written;
    cout << format("... written {} lines of code...\n", _code_written);
    return _code_written < _daily_quota_of_code ? NEED_DRINK : WRITTEN_ENOUGH_CODE;
}

Programmer::State Programmer::look_busy() {
    // lambdas
    auto goingHomeMsg = [this](bool enoughCode) -> string {
        auto msg = string{};
        if (enoughCode) {
            msg = format("written {} lines of code\n", _code_written);
        }
        else {
            msg = "Drink Machine needs refilling";
        }
        return "\nGoing home because " + msg;
    };

    // algorithm
    if (_state == QUIT) return QUIT;
    cout << _name << ": ";
    switch (_state) {
    case NO_MACHINE: _state = drinkMachine();
        if (_state == NO_MACHINE) cout << "No Drink Machine assigned.\n";
        break;
    case NEED_DRINK: _state = take_sip();
        break;
    case CAN_WRITE_CODE: _state = write_code();
        break;
    case EMPTY_CUP: _state = get_drink("Get another drink");
        break;
    case MACHINE_NEEDS_REFILLING:
        cout << "Hoppers need filling.\n";
        _state = GO_HOME;
        break;
    case WRITTEN_ENOUGH_CODE:
    case GO_HOME:
        cout << goingHomeMsg(_state == WRITTEN_ENOUGH_CODE) << endl;
        _state = QUIT;
        break;
    case UNRECOVERABLE_ERROR: _state = QUIT;
        break;
    default:;
    }

    //cout << "\nGoing home because ";
    //if (drinkOK) {
    //    cout << "written " << _code_written << " lines of code";
    //}
    //else {
    //    cout << "Drink Machine need refilling";
    //}
    //cout << endl;
    return _state;
}