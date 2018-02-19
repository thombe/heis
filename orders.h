//Order module for elevator TTK4235
#include <stdlib.h>
#include <stdio.h>
#include "elev.h"

#define N_BUTTONS 3

struct orders
{
  int button_channel_matrix;
  int orders[N_FLOORS][N_BUTTONS];

};


int get_order(elev_button_type_t dir, int floor);

int add_order(int floor, int DIR);

int del_order();
