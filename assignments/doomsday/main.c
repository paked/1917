// main.c
// Find the day of the week of an arbitrary date using the 
// using the doomsday method.
// Written by Harrison Shoebridge on 17/3/15.
// 
// I didn't copy Richards code, so I'm not using Creative Commons.
// MIT for the win!

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6

#define JANUARY  1
#define FEBRUARY 2
#define MARCH 3
#define APRIL 4
#define MAY 5
#define JUNE 6
#define JULY 7
#define AUGUST 8
#define SEPTEMBER 9
#define OCTOBER 10
#define NOVEMBER 11
#define DECEMBER 12

#define TRUE 1
#define FALSE 0

#define DAYS_PER_WEEK 7

int dayOfWeek(int doomsday, int leapYear, int month, int day);
int anchorForMonth(int leapYear, int month);

int main(int argc, char * argv[]) {
	printf("Hello, world!\n");
	return EXIT_SUCCESS;
}

int dayOfWeek(int doomsday, int leapYear, int month, int day) {
	int dayOfWeek = MONDAY;	
	int anchor = anchorForMonth(leapYear, month); 
	// find the difference between the anchor and the wanted day
	
	// add distance onto anchor and mod DAYS_IN_WEEK.

	printf("the anchor is%d\n", anchor);

	return dayOfWeek;
}

int anchorForMonth(int leapYear, int month) {
	assert(month <= DECEMBER);
	
	// Find the anchor day
	if(month == JANUARY && !leapYear) {
	
	}else if (month == JANUARY && leapYear) {
	
	}else if (month == FEBRUARY && !leapYear) {
	
	}else if (month == FEBRUARY && leapYear) {
		
	}else if (month == MARCH) {
	
	}else if (month == APRIL) {
	
	}else if (month == MAY) {
	
	}else if (month == JULY) {
	
	}else if (month == AUGUST) {
	
	}else if (month == SEPTEMBER) {
	
	}else if (month == OCTOBER) {
	
	}else if (month == NOVEMBER) {
	
	}else if (month == DECEMBER) {
	
	}

	return 0;
}
