#include <stdio.h>

double factorial(int n); /*wrong */

int main(void) {
	int n;
	printf("Enter an int: ");
	scanf("%d", &n);
	printf("%f\n", factorial(n));
	return 0;
}

double factorial(int n) {
	if (n == 0 || n == 1)
		return 1;
	else
		return (n * factorial(n--)); /* sequence point: the order things happen is not clear -> undefined */
	}
