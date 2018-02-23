//Order module for elevator TTK4235
#ifndef orders_H
#define orders_H

#include "elev.h"
#define N_BUTTONS 3
#define N_FLOORS 4



static int orders[N_FLOORS][N_BUTTONS];
static int current_order = 0;



//Function takes floor and dir and returns non-zero if there exists order
int get_order(elev_button_type_t dir, int floor);

//Function adds any order and illuminates button lamp.
void add_order();


int del_order();

//Function loops through and flushes orders. Should be called when entering emergency state
void flush_orders();
