#include <stdio.h>
int factorial(int n);
/* factorial(3);

Will go through the following:

    Is 3 equal to 1?
    It is not so it returns 3*factorial(2)
    In order to obtain 3*factorial(2), it calculates factorial(2).
    Now it checks: is 2 equal to 1?
    It is not so it returns 2*factorial(1), since it is returning to the step three, that overall return will now be 3*2*factorial(1).
    Next the program checks: is 1 equal to 1?
    It is so it returns 1. */
int main(void) {
	int n, f;
	
	printf("To find factorial n, enter n: ");
	scanf("%d", &n);
	
	f = factorial(n);
	printf("%d", f);
	return 0;
}

int factorial(int n) {
	
		if (n <= 1)
			return n;
		else
			return(n * factorial(n - 1));
		}
