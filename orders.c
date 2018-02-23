//Order module for elevator TTK4235
#include "orders.h"
#include "elev.h"
#include <stdlib.h>
#include <stdio.h>

int get_order(elevator_button_type_t dir, int floor)
{
  switch(dir)
  {
    case(BUTTON_CALL_UP):
      return elev_get_button_signal(BUTTON_CALL_UP,floor);
      break;
    case(BUTTON_CALL_DOWN):
      return elev_get_button_signal(BUTTON_CALL_DOWN, floor);
      break;
    case(BUTTON_COMMAND):
      return elev_get_button_signal(BUTTON_COMMAND, floor);
      break;
    default:
      printf("Elevator button type is not valid.");
      break;
  }
}

void flush_orders()
{
	for(int i = 0; i < N_FLOORS; ++i) {
		for(int j = 0; j < N_BUTTONS; ++j){
		orders[i][j] = 0;
		}
	}
}

int get_current_order()
{
	return current_order;
}

void set_current_order()
{
	for (int i = 0; i < N_FLOORS; i++) {
		for (int j = 0; j < N_BUTTONS; j++) {
			if (orders[i][j]) {
				current_order = i;
				return;
			}
		}
	}
}
