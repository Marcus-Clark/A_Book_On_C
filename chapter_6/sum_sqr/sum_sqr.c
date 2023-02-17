#include "sum_sqr.h"

double sum_square(double (*f)(double x), int m, int n)
{
	int 		k;
	double 		sum = 0.0;
	
	for (k = m; k <= n; ++k)
		sum += (*f)(k) * (*f)(k);
	return sum;
}
