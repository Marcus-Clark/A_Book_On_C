#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int month(void);

int main(void) {
srand(time(NULL));
int i, jan = 0, feb = 0, other = 0;
for (i = 0; i < 10; ++i) {
    
		if (month() == 1) {
			++jan;
		} else if (month() == 2) {
			++feb;
		} else {
			++other;
		}
		}
		printf("jan: %d feb %d other: %d\n", jan, feb, other);
	if (jan > 1 || feb > 1)
			printf("Trial TRUE\n");

return 0;
}

int month(void) {
	int month;
	month = rand() % 12 + 1;
	return month;	
}

