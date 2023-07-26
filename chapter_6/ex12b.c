#include <stdio.h>

#define		N 	5



double poly;

double eval(double p[], double x, int n); /* n is max degree */

int main(void)
{
double 	p[N + 1] = {1, 1, 1, 1, 1 ,1};
	
	
	printf("%f\n", eval(p, 5, N)); 
	 
	return 0;
}

double eval(double p[], double x, int n)
{
        poly = p[0]  + p[1] * (x  ) + p[2] * (x * x ) + p[3] * (x * x * x) + p[4] * (x  * x * x * x ) + p[5] * (x * x * x * x * x)  ;
		return poly;
	
}
