#include <stdio.h>

#define		N 	2


int i, x;
double poly;

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
	poly = p[0];
    for (i = 1; i <= n; i++)
    {
        poly = poly * x + p[i];
    }
    return poly;
	
}
