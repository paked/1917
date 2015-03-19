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
	printf("Testing dayOfWeek\n");

	assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);
	assert (dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY);
	assert (dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY);
	assert (dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
	assert (dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY);
	assert (dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY);
	assert (dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY);
	assert (dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY);
	assert (dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY);
	assert (dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY);

	assert (dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY);
	assert (dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY);
	assert (dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY);
	assert (dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY);
	assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
	assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
	assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
	assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
	assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
	assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY);

	assert (dayOfWeek (TUESDAY,   FALSE,  2,  28) == TUESDAY);
	assert (dayOfWeek (TUESDAY,   FALSE,  2,  27) == MONDAY);
	assert (dayOfWeek (THURSDAY,  FALSE,  1,  3)  == THURSDAY);

	return EXIT_SUCCESS;
}

// dayOfWeek returns the day of the week which a given date lands on
// It takes four arguments:
//  * doomsday - the day which the doomsday lands on for that year
//  * leapYear - a boolean value, whether or not the year is a leap
//  * month    - the month of the given date
//  * day      - the day of the given date
//
//  It returns a value between 0-6, which should usually be compared
//  against one of the "day" constants (MONDAY, TUESDAY, WEDNESDAY, etc)
int dayOfWeek(int doomsday, int leapYear, int month, int day) {
    int anchor = anchorForMonth(leapYear, month);
    int dayOfWeek = (doomsday + (day - anchor)) % 7;
    if (dayOfWeek < 0) {
        dayOfWeek = 7 - (dayOfWeek * -1);
    }

    return dayOfWeek;
}

// anchorForMonth finds the anchor day for the specified month, 
// taking into account whether or not it is a yeapYear.
// It takes two arguments:
//  * leapYear - a boolean value, whether or not the year is a leap year
//  * month    - the month that is being checked
//
// When possible, anchor dates closer to the middle of the month were
// used for cleanliness.
// In practice it will return an integer between 3 and 22 (the lowest
// and highest anchor days)
int anchorForMonth(int leapYear, int month) {
	int anchor = 0;
	
    // Validate inputs (month is a month, leapYear is boolean)
    assert(month >= JANUARY && month <= DECEMBER);
    assert(leapYear == TRUE || leapYear == FALSE);

	// Find the anchor day
	if(month == JANUARY && !leapYear) {
		anchor = 3;	
	}else if (month == JANUARY && leapYear) {
		anchor = 11;
	}else if (month == FEBRUARY && !leapYear) {
		anchor = 14;
	}else if (month == FEBRUARY && leapYear) {
		anchor = 22;
	}else if (month == MARCH) {
		anchor = 14;
	}else if (month == APRIL) {
		anchor = 4;
	}else if (month == MAY) {
		anchor = 9;
	}else if (month == JUNE) {
		anchor = 6;
	}else if (month == JULY) {
		anchor = 11;
	}else if (month == AUGUST) {
		anchor = 8;
	}else if (month == SEPTEMBER) {
		anchor = 5;	
	}else if (month == OCTOBER) {
		anchor = 10;
	}else if (month == NOVEMBER) {
		anchor = 7;
	}else if (month == DECEMBER) {
		anchor = 12;
	}

	return anchor;
}
