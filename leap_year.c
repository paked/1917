// Calculate if the number is a leap year!
// Week x :)
// Harrison Shoebridge!

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define START_OF_GREGORIAN_CALENDAR 1582

int main(int argc, char * argv[]) {
	int year;
	printf("please enter the year you are interested in\n");
	scanf("%d", &year);
	
	assert(year > START_OF_GREGORIAN_CALENDAR);
	
	if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) { 
		printf("%d is a leap year!\n", year);
	}else {
		printf("%d is not a leap year!\n", year);
	}

	return 0;
}
