/*
State machine module for elevator project TTK4235
Module implements state machine functionality for the elevator
2018
*/

#ifndef state_H
#define state_H

typedef enum {
     UNINIT,
     WAIT,
     UP,
     DOWN,
     REACHED,
     ATFLOOR,
     PICKUP,
     EMERGENCY,
     WAITE
 } States;

//Variable that holds current state. Only accesable for state module
static States state = UNINIT;

//Function that sets static variable state in module.
void change_state(States s);

//Function returns state as state
States get_state();

//Function returns state as char*, for testing purposes
char* get_state_string();

//Function to be called when entering EMERGENCY state. Returns 1 if door opens.
int enter_emergency();

//Function to be called when entering REACHED state.
void reach_floor();

//Main state machine functionality
void run_state_machine();

#endif
