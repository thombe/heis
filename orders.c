#include "orders.h"
#include "elev.h"

for(int i = 0; i < N_FLOORS; ++i){
	for(int j = 0; j < N_BUTTONS; ++j){
		orders[i][j] = 0;
	}
}


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

int add_order()
{
  for(int floors=0; floors < N_FLOORS; ++floors)
  {
    for(int button_type=BUTTON_CALL_UP; button_type <= BUTTON_COMMAND; ++button_type)
    {
      if(get_order(button_type, floors) == 1) // button_type at floor is detected
      {
        order[floors][button_type] = 1;
        elev_set_button_lamp(button_type, floors, 1);
      }
    }
  }
}






void flush_orders()
{
	for(int i = 0; i < N_FLOORS; ++i){
		for(int j = 0; j < N_BUTTONS; ++j){
		  orders[i][j] = 0;
		}
	}
}
