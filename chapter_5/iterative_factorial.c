#include <stdio.h>

int factorial(int n);	/* iterative version */

int main(void) {
	int n;
	
	printf("Enter a positive integer: ");
	scanf("%d", &n);
	
	printf("factorial %d is %d\n", n, factorial(n));
	
	
	return 0;
}
int factorial(int n) {
	
	int product = 1;
	
	for ( ; n > 1; --n)
		product *= n;
	return product;
}
