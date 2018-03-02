//Order module for elevator TTK4235
#include "orders.h"
#include "elev.h"
#include <stdlib.h>
#include <stdio.h>

int get_order(elev_button_type_t dir, int floor)
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

void add_order()
{
  for(int floors=0; floors < N_FLOORS; ++floors)
  {
    for(int button_type=BUTTON_CALL_UP; button_type <= BUTTON_COMMAND; ++button_type)
    {
      if(button_type == BUTTON_CALL_UP && floors == N_FLOORS-1)
      {
        continue;
      }
      if(button_type == BUTTON_CALL_DOWN && floors == 0)
      {
        continue;
      }

      if(get_order(button_type, floors) == 1) // button_type at floor is detected
      {
        orders[floors][button_type] = 1;
        elev_set_button_lamp(button_type, floors, 1);
      }
    }
  }
}

void del_order(int floor)
{
	for (int i = 0; i < N_BUTTONS; i++) {
		orders[floor][i] = 0;
        for (int button_type = BUTTON_CALL_UP; button_type <= BUTTON_COMMAND; ++button_type) {
            if(button_type == BUTTON_CALL_UP && floor == N_FLOORS-1)
            {
              continue;
            }
            if(button_type == BUTTON_CALL_DOWN && floor == 0)
            {
              continue;
            }
            elev_set_button_lamp(button_type , floor , 0);
        }
	}
}


void flush_orders()
{
  for(int floors=1; floors < N_FLOORS; ++floors)
  {
    for(int button_type=BUTTON_CALL_UP; button_type <= BUTTON_COMMAND; ++button_type)
    {
      if(button_type == BUTTON_CALL_UP && floors == N_FLOORS-1)
      {
        continue;
      }
      if(button_type == BUTTON_CALL_DOWN && floors == 0)
      {
        continue;
      }

        orders[floors][button_type] = 0;
        elev_set_button_lamp(button_type, floors, 0);
    }
  }
  current_order = -1;
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
    current_order = -1;
}

int check_floor_dir(int floor_order, elev_motor_direction_t dir)
{
    if (dir == 1) {
        return orders[floor_order][0] == 1;
    } else {
        return orders[floor_order][1] == 1;
    }
}

void del_order_and_dir(int floor , elev_motor_direction_t dir)
{
    for(int button_type=BUTTON_CALL_UP; button_type <= BUTTON_COMMAND; ++button_type){
        if(button_type == BUTTON_CALL_UP && floor == N_FLOORS-1){
            continue;
        }
        if(button_type == BUTTON_CALL_DOWN && floor == 0) {
            continue;
        }
        orders[floor][button_type] = 0;
        elev_set_button_lamp(button_type , floor , 0);
    }
}

void add_order_reversed()
{
  for(int floors=N_FLOORS-1; floors >= 0; --floors)
  {
    for(int button_type=BUTTON_CALL_UP; button_type <= BUTTON_COMMAND; ++button_type)
    {
      if(button_type == BUTTON_CALL_UP && floors == N_FLOORS-1)
      {
        continue;
      }
      if(button_type == BUTTON_CALL_DOWN && floors == 0)
      {
        continue;
      }

      if(get_order(button_type, floors) == 1) // button_type at floor is detected
      {
        orders[floors][button_type] = 1;
        elev_set_button_lamp(button_type, floors, 1);
      }
    }
  }
}
