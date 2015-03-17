// main.c
// Find the day of the week of an arbitrary date using the 
// using the doomsday method.
// Written by Harrison Shoebridge on 17/3/15.
// 
// I didn't copy Richards code, so I'm not using Creative Commons.
// MIT for the win!

#include <stdio.h>
#include <stdlib.h>

#define MONDAY 0
#define TUEDAY 1
#define WEDNESDAY 2
#define THURSDAY 3
#define FRIDAY 4
#define SATURDAY 5
#define SUNDAY 6

int dayOfWeek(int doomsday, int leapYear, int month, int day);

int main(int argc, char * argv[]) {
	printf("Hello, world!\n");
	return EXIT_SUCCESS;
}

int dayOfWeek(int doomsday, int leapYear, int month, int day) {
	int dayOfWeek = MONDAY;

	return dayOfweek
}
