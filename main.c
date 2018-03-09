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


    while (1) {
        run_state_machine();
        add_order();
		    if (elev_get_stop_signal() && get_state() != EMERGENCY) {
            change_state(EMERGENCY);
        }
    }


    return 0;
}
