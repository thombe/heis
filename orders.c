#include "orders.h"
#include "elev.h"

int get_order(elevator_motor_dir_t dir, int floor)
{
  switch(elev_button_type_t)
  {
    case(BUTTON_CALL_UP):
      return elev_get_button_signal(BUTTON_CALL_UP,floor);
    case(BUTTON_CALL_DOWN):
      return elev_get_button_signal(BUTTON_CALL_DOWN, floor);
    case(BUTTON_COMMAND):
      return elev_get_button_signal(BUTTON_COMMAND, floor);
  }
}
