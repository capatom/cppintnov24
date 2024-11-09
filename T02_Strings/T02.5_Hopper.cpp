#include "T02.5_Hopper.h"
#include <cassert>

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