#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int month(void);
int count_month(void);
int test(void);
/* program to calculate the probability n people share the same birth month */
int main(void) {
	srand(time(NULL));
	
	int i,  true = 0;
	float probability;
	for (i = 0; i < 1000; ++i) {
		if (test() == 1)
		++true;
	}
	probability = (float)true / 1000; /*cast to float */
	printf("%f ", probability);
	return 0;
}

int month(void) {
	int month;
	month = lrand48() % 12 + 1; /*computes month of birth for each person */
	return month;	
}

int count_month(void) { /* counts how often each month occurs */
	
int i, jan = 0, feb = 0, mar = 0, apr = 0, may = 0, jun = 0, jul = 0, aug = 0, sep = 0, oct = 0, nov = 0, dec = 0;
for (i = 0; i < 3; ++i) { /* repeats call to month() i < n times - represents number of people */
    
		if (month() == 1) {
			++jan;
		} else if (month() == 2) {
			++feb;
		} else if (month() == 3) {
			++mar;
		} else if (month() == 4) {
			++apr;
		} else if (month() == 5) {
			++may;
		} else if (month() == 6) {
			++jun;
		} else if (month() == 7) {
			++jul;
		} else if (month() == 8) {
			++aug;
		} else if (month() == 9) {
			++sep;
		} else if (month() == 10) {
			++oct;
		} else if (month() == 11) {
			++nov;
		} else  {
			++dec;
		} 
	}
		/*printf("jan: %d feb %d mar %d apr %d may %d jun %d jul %d aug %d sep %d oct %d nov %d dec %d\n", 
				jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec); */
	if (jan > 1 || feb > 1 || mar > 1 || apr > 1 || may > 1 || jun > 1 || jul > 1 || aug > 1|| sep > 1 || oct > 1 || nov > 1 || dec > 1)
			return 1;
	else
			return 0;
}
int test(void) {
	int test;
test = count_month(); /* count the months and then test if any occur more than once */

if (test == 1)
	return 1;
else
	return 0;
}
