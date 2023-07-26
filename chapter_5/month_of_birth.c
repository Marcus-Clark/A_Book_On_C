#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int month(void);

int main(void) {
srand(time(NULL));
int i;
for (i = 0; i < 20; ++i) {
    printf("%d ", month());
   
	
}
return 0;
}

int month(void) {
	int month;
	month = rand() % 12 + 1;
	return month;	
}

