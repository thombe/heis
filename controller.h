/*
Elevator controller module for elevator project TTK4235
Module implements controller for the elevator
2018
*/

#ifndef controller_H
#define controller_H

#include "elev.h"
//DIR holds current direction of elevator
static elev_motor_direction_t DIR = 0;
static int last_floor;
static int last_dir = 0; // Used for checking after emergency.
//Is not set to 0 when elevator stops.

/*
   Function sets last floor visited given by @param floor.
   0 is ground floor, 3 is top
*/
void set_DIR(elev_motor_direction_t d);

/*
   Function @return current direction (DIRN_DOWN = -1,
   DIRN_STOP = 0, DIRN_UP = 1)
*/
elev_motor_direction_t get_DIR();


/*
   Function @return current direction in STRING format
*/

char* get_DIR_string();

/*
   Function sets last floor visited given by @param floor.
   0 is ground floor, 3 is top
*/
void set_last_floor(int f);

/*
  Function @return last floor (0-3) visited
*/
int get_last_floor();


/*
  Function initilizes the elevator. If the elevator is between two floors, it
  will by default move DOWN until floor is detected.
  @return 1 when elevator is at a floor with its door closed
*/

int initialize();

/*
  Function @return last direction (DIRN_DOWN = -1,
  DIRN_STOP = 0, DIRN_UP = 1) visited
*/
int get_last_dir();

#endif
