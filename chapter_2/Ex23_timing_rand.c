#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define 	NCALLS	100000000		/*number of fct calls							*/
#define 	NCOLS	5				/*number of columns, 5 to fit larger numbers	*/
#define		NLINES	3				/*number of lines								*/

int main(void) {
	int		i, val;
	long 	begin, diff, end;
	
	begin = time(NULL);
	srand(time(NULL));
	printf("\nTiming Test: %d calls to rand()\n\n", NCALLS);
	for (i = 1; i<= NCALLS; ++i) {
		val = rand();
		if (i <= NCOLS * NLINES) {
			printf("%12d", val); /*%12d to fit width of random numbers */
			if (i % NCOLS == 0)
				putchar('\n');
			}
		else if (i == NCOLS * NLINES + 1)
			printf("%12s\n\n", ".......");
		}
		end = time(NULL);
		diff = end - begin;
		printf("%s%ld\n%s%ld\n%s%ld\n%s%.10f\n\n",
			"	    end time: ", end,
			"	  begin time: ", begin,
			"	elapsed time: ", diff,
			"  time for each call: ", (double) diff / NCALLS);
		return 0;
	}
		
