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
            break;
        case DOWN:
            set_DIR(DIRN_DOWN);
            break;
        case REACHED:
            reach_floor();
            del_order(get_last_floor());
	        set_current_order();
            break;
        case ATFLOOR:
            set_last_floor(elev_get_floor_sensor_signal());
            break;
        case PICKUP:
            reach_floor();
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
    start_timer(3);
    printf("reach_floor called");
}

void run_state_machine()
{
    int cur_ord = get_current_order();
    int last_floor = get_last_floor();
    int cur_floor = elev_get_floor_sensor_signal();
    printf("last floor is %d and current order is %d\n", last_floor , cur_ord);
    switch (state) {
        case UNINIT:
            initialize();
            change_state(WAIT);
            break;
        case WAIT:
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
            if (cur_floor != -1) {
                change_state(ATFLOOR);
            }
            break;
        case DOWN:
            if (cur_floor != -1) {
                change_state(ATFLOOR);
            }
            break;
        case ATFLOOR:
            if (cur_floor == cur_ord) {
                change_state(REACHED);
            } //Her skal det sjekkes om order matcher retning og etasje, skal sendes til PICKUP state
            break;
        case PICKUP:
            if (duration_passed()) {
                change_state(WAIT); //kanske dette ikke funker..
            }
            break;
        case REACHED:
            if (duration_passed()) {
                change_state(WAIT);
            }
            break;
    }
}
