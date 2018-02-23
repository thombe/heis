//Order module for elevator TTK4235
#include <stdlib.h>
#include <stdio.h>
#include "elev.h"

#define N_BUTTONS 3

//Matrix for holding all orders.
static int orders[N_FLOORS][N_BUTTONS];
//Variable for holding current order. -1 means no order.
static int current_order = -1;



//Function takes floor and dir and returns non-zero if there exists order
int get_order(elev_button_type_t dir, int floor);

//Function adds any order and illuminates light.
int add_order();

int del_order();

//Function loops through and flushes orders. Should be called when entering emergency state
void flush_orders();

//Function returns current order value
int get_current_order();

//Function to set current order to first it can find in matrix.
void set_current_order();
