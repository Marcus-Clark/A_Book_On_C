#include <stdio.h>

#define		N 	2


int i, x;
double polySum;

double eval(double p[], double x, int n); /* n is max degree */

int main(void)
{
double 	p[N + 1] = {1, 1, 0};
	x = 1;
	
	printf("%f\n", eval(p, 5, N)); 
	 
	return 0;
}

double eval(double p[], double x, int n)
{
	polySum = p[0];
    for (i = 1; i <= n; i++)
    {
        polySum = polySum * x + p[i];
    }
    return polySum;
	
}
