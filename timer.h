/*
Timer module for TTK4235 elevator
Module provides simple timer functions for elevator.
Only works for integer amount of seconds
2018 thombe
*/


#ifndef timer_H
#define timer_H

// Function converts timeval struct to double
// From "Intro-to-C-Linux" TTK4235

int get_wall_time(void);
//git comment
//another git comment

// Function starts timer and sets duration to int dur.

void start_timer(int dur);

// Function stops/resets timer. Not really that helpful for this project.

void stop_timer(void);

// Function checks whether current time - start time > duration

int duration_passed(void);

#endif
