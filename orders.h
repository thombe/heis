/*
   Order module for elevator project TTK4235.
   Module implements necessary functions (add, get, set, delete and check functions)
   for orders matrix and current order variable
   2018
*/

#ifndef orders_H
#define orders_H

#include "elev.h"
#define N_BUTTONS 3
#define N_FLOORS 4


//Matrix for holding all orders. 0 means no order.
static int orders[N_FLOORS][N_BUTTONS];


//Variable for holding current order. -2 means no order.
static int current_order = -2;


/*
  Function detects if @param button_dir (BUTTON_CALL_UP,
  BUTTON_CALL_DOWN or BUTTON_COMMAND) at @param floor (0-3)
  is pressed (i.e. order placed).
  @return 1 if button_dir at floor is pressed. 0 if not.
*/
int get_order(elev_button_type_t dir, int floor);


/*
  Function adds any valid order detected to the orders matrix (assign element to 1),
  skip not possible orders (i.e. button down and first floor, button up and last floor)
  and illuminates button lamp if valid order at floor is detected.
*/
void add_order();


/*
  Function deletes valid order at @param floor (0-3),
  and disilluminates button lamp at @param floor.
*/
void del_order(int floor);


/*
  Function flushes/deletes all orders in orders matrix.
  Sets current order to -2. 
*/
void flush_orders();


/*
  Function gets current order
  @return current_order, i.e. -2 for no order
  and 0-3 for respectively orders at first, second, third and fourth floor.
*/
int get_current_order();


/*
  Function sets current_order variable based on elevator direction to get
  equal prioritization for all orders. If no order exist, current order is set to -2
  If direction is DOWN, function sets first element it can find in orders as current order.
  If direction is UP, function sets last element it can find in orders as current order.
*/
void set_current_order();


/*
  Function check direction @param dir of the elevator against order type
  (button_up, button_down or button_command) at floor @param floor_order
  @return 1 if elevator direction and order with the same direction match, or
  if button_command order exists. 0 otherwise.
*/
int check_floor_dir(int floor_order, elev_motor_direction_t dir);


#endif
