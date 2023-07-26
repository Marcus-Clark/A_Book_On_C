#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int i, zero_cnt, one_cnt;
	
	for (i = 0; i < 1000; ++i) {
		if (i % 30 == 0)
			putchar('\n');
		if ((lrand48() % 2) == 0)
			++zero_cnt;
		else
			++one_cnt;
		printf("%2ld", lrand48() % 2);
}
		printf("\n\n");
		printf("There are %d 0s and %d 1s\n", zero_cnt, one_cnt);
		
	return 0;
}
