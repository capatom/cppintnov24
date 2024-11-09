#include "T14.3_Drink.h"
#include <cassert>

bool Drink::take_sip(int sip) {
    assert(sip > 0);
    bool someLeft = _volume > 0;
    if (sip > _volume) _volume = 0;
    else _volume -= sip;
    return someLeft;
}
