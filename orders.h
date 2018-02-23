//Order module for elevator TTK4235
#ifndef orders_H
#define orders_H

#include "elev.h"
#define N_BUTTONS 3
#define N_FLOORS 4

//Matrix for holding all orders.
static int orders[N_FLOORS][N_BUTTONS];
//Variable for holding current order. -1 means no order.
static int current_order = -1;



//Function takes floor and dir and returns non-zero if there exists order
int get_order(elev_button_type_t dir, int floor);

<<<<<<< HEAD
//Function adds any order and illuminates button lamp.
void add_order();

=======
//Function adds any order and illuminates light.
<<<<<<< HEAD
int add_order();
>>>>>>> 50ab2dfb1bea736279c83e3323b10bffd8719b21
=======
void add_order();
>>>>>>> fd6506513f06c22525441f8d3f416244425921c5

//function deletes orders at floor
void del_order(int floor);

//Function loops through and flushes orders. Should be called when entering emergency state
void flush_orders();
<<<<<<< HEAD
=======


//Function returns current order value
int get_current_order();

//Function to set current order to first it can find in matrix.
void set_current_order();
#endif
>>>>>>> 50ab2dfb1bea736279c83e3323b10bffd8719b21
