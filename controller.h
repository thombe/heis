/*
Elevator controller module for elevator project TTK4235
Module implements controller for the elevator
2018 thombe
*/

#ifndef controller_H
#define controller_H

static elev_motor_direction_t DIR = 0;
static int last_floor;

//Function sets motor direction
void set_DIR(elev_motor_direction_t d);

//Function returns current direction
elev_motor_direction_t get_DIR();

//Function return current direction as string
char* get_DIR_string();

//Function sets last floor visited. 0 is ground floor, 3 is top
void set_last_floor(int f);

//Function returns last floor visited. 0 is ground floor, 3 is top
int get_last_floor();

#endif
