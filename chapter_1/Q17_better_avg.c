/* Compute a better average. */

#include<stdio.h>
/* if used with a list of numbers approx 600 000 000 and not varying by more than 10
 * will produce behaviour described in Ex17 p65. Notice that type is now float, not double.
 * This is dues to loss of mantissa bits												*/
int main(void)
{
	int     i;
	float  x;
	float  avg    =  0.0; /* a better average */
	float  navg;          /* a naive average */
	float  sum    =  0.0;

	printf("%5s%17s%17s%17s\n%5s%17s%17s%17s\n\n",
	    "Count", "Item", "Average", "Naive avg",
	    "-----", "----", "-------", "------");

	for (i = 1; scanf("%f", &x) == 1; ++i) /*%f not %lf */
	{
		avg += (x - avg) / i;
		sum += x;
		navg = sum / i;
		printf("%5d%17e%17e%17e\n", i, x, avg, navg);
	}
	return 0;
}
