// Calculate if the number is a leap year, using a function!
// Week x :)
// Harrison Shoebridge!

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define START_OF_GREGORIAN_CALENDAR 1582

int isLeapYear(int year) {	
	assert(year > START_OF_GREGORIAN_CALENDAR);
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0); 
}

int main(int argc, char * argv[]) {
	int year;
	printf("What year are you interested kind sir/madam!?\n");
	scanf("%d", &year);
	
	int result = isLeapYear(year);
	if (result == 1) {
		printf("%d is a leap year\n", year);
	}else {
		printf("%d is not a leap year\n", year);
	}
	return 0;
}

