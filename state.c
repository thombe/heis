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
        case UNINIT: return "uninit";
        case WAIT: return "wait";
        case UP: return "up";
        case DOWN: return "down";
        case REACHED: return "reached";
        case EMERGENCY: return "emergency";
        default: return "undefined value";
    }
}
