/*
Elevator controller module for elevator project TTK4235
Module implements controller for the elevator
2018
*/

#include "controller.h"
#include "elev.h"
#include <stdio.h>
void set_DIR(elev_motor_direction_t d)
{
    DIR = d;
    elev_set_motor_direction(d);
    if (d != 0) {
        last_dir = d;
    }
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

int initialize()
{
    while (elev_get_floor_sensor_signal() == -1) {
		set_DIR(DIRN_DOWN);
    }
	set_DIR(DIRN_STOP);
    set_last_floor(elev_get_floor_sensor_signal());
    return 1;
}
int get_last_dir()
{
    return last_dir;
}
