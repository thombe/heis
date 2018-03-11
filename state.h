/*
State machine module for elevator project TTK4235
Module implements state machine functionality for the elevator
2018
*/

#ifndef state_H
#define state_H

//Enum contains all possible states.
typedef enum {
     UNINIT,
     WAIT,
     UP,
     DOWN,
     ATFLOOR,
     EMERGENCY
 } States;


 //Variable that holds current state. Only accesable for state module.
static States state = UNINIT;


/*
  Function for changing states (given by States enum).
  Sets state variable to @param s.
*/
void change_state(States s);


/*
  Function gets state variable.
  @return state as States (enum).
*/
States get_state();


/*
  Function gets state variable. Only used for testing purposes.
  @return state as char*.
*/
char* get_state_string();


/*
  Function implements state machine functionality.
  Contains all state logic necessary to run the elevator.
*/
void run_state_machine();


#endif
