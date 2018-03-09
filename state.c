/*
State machine module for elevator project TTK4235
Module implements state machine functionality for the elevator
2018
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
            set_current_order();
            elev_set_door_open_lamp(0);
            break;
        case UP:
            set_DIR(DIRN_UP);
            break;
        case DOWN:
            set_DIR(DIRN_DOWN);
            break;
        case ATFLOOR:
            start_timer(3);
            set_DIR(DIRN_STOP);
            elev_set_door_open_lamp(1);
            set_last_floor(elev_get_floor_sensor_signal());
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
        case ATFLOOR: return "atfloor";
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
void run_state_machine()
{
    int cur_ord = get_current_order();
    int last_floor = get_last_floor();
    int cur_floor = elev_get_floor_sensor_signal();
    printf("FLOOR: %d\t ORDER: %d\t STATE %s\t DIR: %s\n", cur_floor , cur_ord , get_state_string() , get_DIR_string());
    switch (state) {
        case UNINIT:
            initialize();
            change_state(WAIT);
            break;
        case WAIT:
            set_current_order();
            if (cur_ord == -2) {
              break;
            } else if (cur_ord > last_floor) {
              change_state(UP);
            } else if (cur_ord < last_floor) {
              change_state(DOWN);
            } else {
                if (cur_floor == cur_ord) {
                    change_state(ATFLOOR);
                } else {
                    switch (get_last_dir()) {
                        case 1:
                        change_state(DOWN);
                        break;
                        case -1:
                        change_state(UP);
                        break;
                    }
                }
            }
        case UP:
            if (cur_floor!= -1) {
                elev_set_floor_indicator(cur_floor);
                if (check_floor_dir(cur_floor , get_DIR())) {
                    change_state(ATFLOOR);
                } else if (cur_floor == cur_ord) {
                    change_state(ATFLOOR);
                }
            }
            break;
        case DOWN:
            if (cur_floor!= -1) {
                elev_set_floor_indicator(cur_floor);
                if (check_floor_dir(cur_floor , get_DIR())) {
                    change_state(ATFLOOR);
                } else if (cur_floor == cur_ord) {
                    change_state(ATFLOOR);
                }
            }
            break;
        case ATFLOOR:
            del_order(get_last_floor());
              if (cur_floor == cur_ord && duration_passed()) {
                change_state(WAIT);
                set_current_order();
            } else if (duration_passed()) {
                elev_set_door_open_lamp(0);
                if (get_last_dir() == 1) {
                    change_state(UP);
                } else if (get_last_dir() == -1) {
                    change_state(DOWN);
                }
            }
            break;
        case EMERGENCY:
            if (!elev_get_stop_signal()) {
                change_state(WAIT);
                elev_set_stop_lamp(0);
            }
    }
}
