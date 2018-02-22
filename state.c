/*
State machine module for elevator project TTK4235
Module implements state machine functionality for the elevator
2018 thombe
*/

#include "state.h"

void change_state(States s)
{
    state = s;
}

States get_state()
{
    return state;
}

char* get_state_string()
{
    switch (state) {
        case uninit: return "uninit";
        case wait: return "wait";
        case up: return "up";
        case down: return "down";
        case reached: return "reached";
        case emergency: return "emergency";
        default: return "undefined value";
    }
}
