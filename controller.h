/*
Elevator controller module for elevator project TTK4235
Module implements controller for the elevator
2018 thombe
*/

#ifndef controller_H
#define controller_H

#include "elev.h"

static elev_motor_direction_t DIR = 0;
static int last_floor;
static int last_dir = 0;

//Function sets direction. 0 = stop, 1 is up , -1 is down
void set_DIR(elev_motor_direction_t d);

//Function returns current direction
elev_motor_direction_t get_DIR();

//Function return current direction as string
char* get_DIR_string();

//Function sets last floor visited. 0 is ground floor, 3 is top
void set_last_floor(int f);

//Function returns last floor visited. 0 is ground floor, 3 is top
int get_last_floor();

//Function returns true when elevator is at a floor with its door closed
int initialize();

//Function returns last direction != 0
int get_last_dir();

#endif
