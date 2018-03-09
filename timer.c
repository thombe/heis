/*
Timer module for TTK4235 elevator
Module provides simple timer functions for elevator.
Only implemented for integer amount of seconds
2018
*/

#define NULL 0
#include "timer.h"
#include "sys/time.h"


int get_wall_time(void)
{
    struct timeval time;
    gettimeofday(&time , NULL);
    return (int)time.tv_sec + (int)time.tv_usec * 0.000001;
}

void start_timer(int dur)
{
    t = get_wall_time();
    duration = dur;
}

int duration_passed(void) {
    return (get_wall_time() - t) >= duration;
}
