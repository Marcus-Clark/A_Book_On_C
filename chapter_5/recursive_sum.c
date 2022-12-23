#include <stdio.h>

int sum(int n);

int main(void) {
	int n;
	printf("This sums the first n numbers. Enter a value for n:  \n");
	scanf("%d", &n);
	printf("sum of first %d numbers is %d\n", n, sum(n));
	
	return 0;
}

int sum(int n) {
	if (n <= 1)
		return n;
	else 
		return(n + sum(n - 1));
	}
