/*
State machine module for elevator project TTK4235
Module implements state machine functionality for the elevator
2018 thombe
*/

#ifndef state_H
#define state_H

enum States { uninit, wait , up , down , reached , emergency };

//Variable that holds current state. Only accesable for state module
static enum States state = uninit;

typedef enum States States;

//Function that sets static variable state in module.
void change_state(States s);

//Function returns state as state
States get_state();

//Function returns state as char*, for testing purposes
char* get_state_string();

#endif
