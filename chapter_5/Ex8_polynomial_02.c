#include <stdio.h>

double f(double a, double b, double c, double x);

int main(void) {
	
	double a, b, c, x, i;
	
	a = 1;
	b = -3;
	c = 2;
	printf("\n x         f(x) \n");
	for (x = 0, i = 0 ; x <= 3.1; x += 0.1, i += 0.1)
		printf("%f %f\n",i,  f(a, b, c, x));
		

	return 0;
		
}

double f(double a, double b, double c, double x) {
	double value;
	
		value = ((a * x + b) * x ) + c;
	
	return value;
		
}
