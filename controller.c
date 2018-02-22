/*
Elevator controller module for elevator project TTK4235
Module implements controller for the elevator
2018 thombe
*/

#include "controller.h"

void set_DIR(elev_motor_direction_t d)
{
    DIR = d;
}

elev_motor_direction_t get_DIR()
{
    return DIR;
}

char* get_DIR_string()
{
    switch (DIR) {
        case -1: return "Down";
        case 0: return "Still";
        case 1: return "Up";
        default: return "Undefined direction";
    }
}

void set_last_floor(int f)
{
    last_floor = f;
}

int get_last_floor()
{
    return last_floor;
}
