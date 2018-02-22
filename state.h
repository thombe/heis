/*
State machine module for elevator project TTK4235
Module implements state machine functionality for the elevator
2018 thombe
*/

#ifndef state_H
#define state_H

enum States { wait , up , down , reached , emergency };

//Variable that holds current state. Only accesable for state module
static enum States state;

typedef enum States States;

//Function that sets static variable state in module.
void change_state(States s);

//Function returns state as state
States get_state();

#endif
