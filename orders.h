//Order module for elevator TTK4235
#ifndef orders_H
#define orders_H

#include "elev.h"
#define N_BUTTONS 3
#define N_FLOORS 4

//Matrix for holding all orders.
static int orders[N_FLOORS][N_BUTTONS];
//Variable for holding current order. -2 means no order.
static int current_order = -2;



//Function takes floor and dir and returns non-zero if there exists order
int get_order(elev_button_type_t dir, int floor);

//Function adds any order and illuminates light.
void add_order();

//function deletes orders at floor
void del_order(int floor);

//Function loops through and flushes orders. Should be called when entering emergency state
void flush_orders();

//Function returns current order value
int get_current_order();

//Function to set current order to first it can find in matrix.
void set_current_order();

//Function check if order at floor is UP (1) or DOWN(-1). Returns true if up
int check_floor_dir(int floor_order, elev_motor_direction_t dir);

//Fuction deletes specific order
void del_order_and_dir(int floor , elev_motor_direction_t dir);

void print();

int check_floor(int floors);


/*
  Function checks that assertions for @param button_type and @param floors are met, i.e. we skip
  orders that do not exist (floor < 0, floor > 3, up_button at floor 3, down_button at floor 0).
  Returns true (1) if order is invalid and false otherwise.
*/
int check_invalid_orders(int floors, int button_type);




#endif
