//Order module for elevator TTK4235
#include <stdlib.h>
#include <stdio.h>
#include "elev.h"

#define N_BUTTONS 3


static int orders[N_FLOORS][N_BUTTONS];



//Function takes floor and dir and returns non-zero if there exists order
int get_order(elev_button_type_t dir, int floor);

//Function adds order with floor number and direction to matrix and illuminates light.
int add_order(elev_button_type_t dir , int floor);

int del_order();

//Function loops through and flushes orders. Should be called when entering emergency state
void flush_orders();
