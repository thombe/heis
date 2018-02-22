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

main(void) {
    
}
