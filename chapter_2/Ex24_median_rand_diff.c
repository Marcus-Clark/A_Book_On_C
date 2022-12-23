#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int		i, above_cnt, below_cnt, val, diff;
	double 	median;
	median = RAND_MAX / 2.0;
	srand(time(NULL));
	
		for (i=0; i <500; ++i) {
		diff = below_cnt + above_cnt;
		val = rand();
			if ( val > median) {
				++above_cnt;
			}
			else if (val < median) {
				--below_cnt;
			}
			printf("difference is:  %d\n", diff);
		}
			printf("Total numbers below median: %d\n", below_cnt);
			printf("Total numbers above median: %d\n", above_cnt);
	return 0;
}
