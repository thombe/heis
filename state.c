/*
State machine module for elevator project TTK4235
Module implements state machine functionality for the elevator
2018 thombe
*/

#include "state.h"
#include "controller.h"
#include "orders.h"
#include "timer.h"
#include "elev.h"
#include <stdio.h>

void change_state(States s)
{
    state = s;
    switch (s) {
        case WAIT:
            elev_set_door_open_lamp(0);
            break;
        case UP:
            set_DIR(DIRN_UP);
            //start_timer(2);
            break;
        case DOWN:
            set_DIR(DIRN_DOWN);
            //start_timer(2);
            break;
        case REACHED:
            reach_floor();
            del_order(get_last_floor());
	        set_current_order();
            break;
        case ATFLOOR:
            set_last_floor(elev_get_floor_sensor_signal());
            //printf("last floor is now %d\n", get_last_floor());
            break;
        case PICKUP:
            reach_floor();
            del_order_and_dir(get_last_floor() , get_DIR());
            break;
        case EMERGENCY:
            enter_emergency();
            break;
	      case UNINIT:
	    break;

    }
}

States get_state()
{
    return state;
}

char* get_state_string()
{
    switch (state) {
        case UNINIT: return "uninit";
        case WAIT: return "wait";
        case UP: return "up";
        case DOWN: return "down";
        case REACHED: return "reached";
        case ATFLOOR: return "atfloor";
        case PICKUP: return "pickup";
        case EMERGENCY: return "emergency";
        default: return "undefined value";
    }
}

int enter_emergency()
{
    elev_set_stop_lamp(1);
    set_DIR(DIRN_STOP);
    flush_orders();
    //Elevator should only open door when it has emergency at floor
    if (elev_get_floor_sensor_signal() != -1) {
        elev_set_door_open_lamp(1);
        return 1;
    }
    return 0;
}
void reach_floor()
{
    set_DIR(DIRN_STOP);
    elev_set_door_open_lamp(1);
    //printf("reach_floor called");
}

void run_state_machine()
{
    int cur_ord = get_current_order();
    int last_floor = get_last_floor();
    int cur_floor = elev_get_floor_sensor_signal();
    //printf("current floor is now set two: \t%d\n", cur_floor);
    int las_floor = get_last_floor();
    //printf("last floor is %d and current order is %d, state is %s\n", last_floor , cur_ord , get_state_string());
    printf("FLOOR: %d\t ORDER: %d\t STATE %s\t DIR: %d\n", cur_floor , cur_ord , get_state_string() , get_DIR());
    switch (state) {
        case UNINIT:
            initialize();
            add_order();
            change_state(WAIT);
            break;
        case WAIT:
            add_order();
            set_current_order();
            switch (cur_ord) {
                case -1:
                    break;
                default:
                    if (cur_ord > last_floor ) {
                        change_state(UP);
                        break;
                    } else if (cur_ord < last_floor) {
                        change_state(DOWN);
                        break;
                    } else {
                        change_state(REACHED);
                        break;
                    }
            }
        case UP:
            add_order_reversed();
            if (cur_floor != -1 && check_floor_dir(cur_floor , get_DIR())) {
                change_state(ATFLOOR);
            } else if (cur_floor == cur_ord) {
                change_state(ATFLOOR);
            }
            if (cur_floor!= -1) {
                elev_set_floor_indicator(cur_floor);
            }
            if (cur_ord < last_floor) {
                change_state(WAIT);
            }
            break;
        case DOWN:
            add_order();
            if (cur_floor != -1 && check_floor_dir(cur_floor , get_DIR())) {
                change_state(ATFLOOR);
            } else if (cur_floor == cur_ord) {
                change_state(ATFLOOR);
            }
            if (cur_floor!= -1) {
                elev_set_floor_indicator(cur_floor);
            }
            break;
        case ATFLOOR:
            add_order();
            start_timer(3);
            if (cur_floor == cur_ord) {
                change_state(REACHED);
            } else {
                change_state(PICKUP);
            }
            //Her skal det sjekkes om order matcher retning og etasje, skal sendes til PICKUP state
            break;
        case PICKUP:
            add_order();
            if (duration_passed()) {
                change_state(WAIT); //kanske dette ikke funker..
            }
            break;
        case REACHED:
            add_order();
            if (duration_passed()) {
                change_state(WAIT);
            }
            //change_state(WAIT);
            break;
        case EMERGENCY:
            if (!elev_get_stop_signal()) {
                change_state(WAIT);
                elev_set_stop_lamp(0);
            }
    }
}
