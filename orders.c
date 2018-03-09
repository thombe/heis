//Order module for elevator TTK4235
#include "orders.h"
#include "elev.h"
#include "state.h"
#include "controller.h"
#include <stdlib.h>
#include <stdio.h>

int get_order(elev_button_type_t dir, int floor)
{
    switch(dir) {
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
    if (get_state()!=EMERGENCY && get_state()!=UNINIT) {
        for(int floors=0; floors < N_FLOORS; ++floors) {
            for(int button_type=BUTTON_CALL_UP; button_type <= BUTTON_COMMAND; ++button_type) {
                if(button_type == BUTTON_CALL_UP && floors == N_FLOORS-1){
                    continue;
                }
                if(button_type == BUTTON_CALL_DOWN && floors == 0) {
                    continue;
                }
                if(get_order(button_type, floors) == 1) {
                    orders[floors][button_type] = 1;
                    elev_set_button_lamp(button_type, floors, 1);
                }
            }
        }
    }
}

void del_order(int floor)
{
    for (int i = 0; i < N_BUTTONS; i++) {
	    orders[floor][i] = 0;
        for (int button_type = BUTTON_CALL_UP; button_type <= BUTTON_COMMAND; ++button_type) {
            if(button_type == BUTTON_CALL_UP && floor == N_FLOORS-1){
                continue;
            }
            if(button_type == BUTTON_CALL_DOWN && floor == 0) {
                continue;
            }
            elev_set_button_lamp(button_type , floor , 0);
        }
    }
}


void flush_orders()
{
    for(int floors=0; floors < N_FLOORS; ++floors) {
        for(int button_type=BUTTON_CALL_UP; button_type <= BUTTON_COMMAND; ++button_type) {
            if(button_type == BUTTON_CALL_UP && floors == N_FLOORS-1){
                continue;
            }
            if(button_type == BUTTON_CALL_DOWN && floors == 0) {
                continue;
            }
            orders[floors][button_type] = 0;
            elev_set_button_lamp(button_type, floors, 0);
        }
    }
    current_order = -2;
}

int get_current_order()
{
	 return current_order;
}

void set_current_order()
{
    if (get_last_dir() == -1) {
        for (int i = 0; i < N_FLOORS; i++) {
            for (int j = 0; j < N_BUTTONS; j++) {
                if (orders[i][j]) {
                    current_order = i;
                    return;
                }
            }
        }
    } else {
        for (int i = N_FLOORS-1; i >= 0; i--) {
            for (int j = (N_BUTTONS-1); j >= 0; j--) {
                if (orders[i][j]) {
                    current_order = i;
                    return;
                }
            }
        }
    }
    current_order = -2;
}


int check_floor_dir(int floor_order, elev_motor_direction_t dir)
{
    if (orders[floor_order][2]) {
        return 1;
    }
    if (dir == 1) {
        return orders[floor_order][0] == 1;
    } else if (dir == -1) {
        return orders[floor_order][1] == 1;
    }
    return 0;

}
