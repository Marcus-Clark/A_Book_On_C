#include <math.h>
#include <stdio.h>

int main(void) {
	double 	x;
	
	printf("The following will be computed: \n");
	printf("The square root of x and x raised to the power of x\n");
	
	while (1) {
		printf("Input x: ");
		if (scanf("%lf", &x) != 1)
			break;
		if (x >= 0.0)
			printf("\n%15s%22.15e\n%15s%22.15e\n%15s%22.15e\n\n",
				"x = ", x,
				"sqrt(x) = ", sqrt(x),
				"pow(x, x) = ", pow(x, x));
		else {
			printf("\nSorry, your number must be non-negative.\n");
				break;
			}
		}
		return 0;
	}
