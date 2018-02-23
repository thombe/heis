#include "elev.h"
#include "orders.h"
#include "controller.h"
#include "state.h"
#include <stdio.h>


int main() {
    // Initialize hardware

    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }

    printf("Press STOP button to stop elevator and exit program.\n");


    while (1) {
		//elev_set_motor_direction(DIRN_DOWN);
		//printf("%s\n" , get_state_string());
        if (get_state() == UNINIT) {
			initialize();
			change_state(WAIT);
		}
		
		add_order();
		if (get_current_order() == -1) {
			set_current_order();
		}
		if(get_current_order() > get_last_floor()) {
			change_state(UP);
		} else if (get_current_order() != -1 && get_current_order() < get_last_floor()) {
			change_state(DOWN);
		} else if (get_current_order() != -1 && elev_get_floor_sensor_signal() != -1) {
			change_state(ATFLOOR);
			if(get_current_order() == get_last_floor()) {
				change_state(REACHED);
			}
		}			
		if (elev_get_stop_signal()) {
            elev_set_motor_direction(DIRN_STOP);
            break;
        }
    }
	

    return 0;
}

/*

        elev_set_motor_direction(DIRN_UP);
        while (1) {
        // Change direction when we reach top/bottom floor
        if (elev_get_floor_sensor_signal() == N_FLOORS - 1) {
            elev_set_motor_direction(DIRN_DOWN);
        } else if (elev_get_floor_sensor_signal() == 0) {
            elev_set_motor_direction(DIRN_UP);
        }

        // Stop elevator and exit program if the stop button is pressed
        if (elev_get_stop_signal()) {
            elev_set_motor_direction(DIRN_STOP);
            break;
        }
	add_order();
    }
*/
