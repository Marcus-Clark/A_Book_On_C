#include <stdio.h>

double sum(double a[], int n);

int main(void) {
	
	double a[4]  ;
	a[4] = {1,2,3,4,5};
	int n = 5;
	
	printf("%f\n", sum(a, n) );
	
	return 0;
	}
	
	double sum(double a[], int n)  /*n is the size of a[] */
	{
		int i;
		double sum = 0.0;
		
		for (i = 0; i < n; ++i)
			sum += a[i];
		return sum;
	}
