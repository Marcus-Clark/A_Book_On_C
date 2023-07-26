#include <stdio.h>

double power(double x, int n);

int main(void) {
	
	double x ;
	int n ;
	
	printf("Enter a base number and a power to raise it to: \n");
	scanf("%lf %d", &x, &n);
	printf("%lf\n", power(x, n));
	
	return 0;
}

double power(double x, int n) {
	
	int i;
	double product = 1;
	
	for (i = 1; i <= n; ++i)
		product *= x;
	return product;
}
	
