#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int		i, above_cnt, below_cnt, val;
	double 	median;
	median = RAND_MAX / 2.0;
	
	
		for (i=0; i <500; i++) {
		val = rand();
			if ( val > median) {
				++above_cnt;
				printf("above_cnt is: %d\n", above_cnt);
			}
			else if (val < median) {
				--below_cnt;
				printf("below_cnt is %d\n", below_cnt);
			}
		}
			printf("Total numbers below median: %d\n", below_cnt);
			printf("Total numbers above median: %d\n", above_cnt);
	return 0;
}
