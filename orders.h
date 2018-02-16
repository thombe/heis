#include <stdio.h>
#include "elev.h"
#include <stdlib.h>


struct Orders
{
  int button_channel_matrix;
  bool orders[N_FLOORS][N_BUTTONS];
}


int get_order(int floor);

int add_order(int floor, int DIR);

int del_order();
