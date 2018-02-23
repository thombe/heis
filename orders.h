//Order module for elevator TTK4235
#include <stdlib.h>
#include <stdio.h>
#include "elev.h"

#define N_BUTTONS 3


static int orders[N_FLOORS][N_BUTTONS];
static int current_order = 0;



//Function takes floor and dir and returns non-zero if there exists order
int get_order(elev_button_type_t dir, int floor);

//Function adds any order and illuminates light.
int add_order();

int del_order();

//Function loops through and flushes orders. Should be called when entering emergency state
void flush_orders();
