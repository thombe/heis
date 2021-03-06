/*
    Timer module for TTK4235 elevator
    Module provides simple timer functions for elevator.
    Only implemented for integer amount of seconds
    2018
*/


#ifndef timer_H
#define timer_H

static int t;
static int duration;

// Function converts timeval struct to double
// From "Intro-to-C-Linux" TTK4235

int get_wall_time(void);

/*
   Function starts timer and sets duration to @param dur.
*/

void start_timer(int dur);

/*
   Function @returns 1 if time since start_timer was called is greater than duration.
*/

int duration_passed(void);

#endif
