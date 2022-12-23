#include <stdio.h>

int gcd(int p, int q);

int main(void) {
	int p, q;
	printf("Enter two numbers: ");
	scanf("%d %d", &p, &q);
	printf("gcd of %d and %d is %d\n", p, q, gcd(p, q));
	return 0;
}

int gcd(int p, int q) {
	int r;
	
	if ((r = p % q) == 0)
		return q;
	else
		return gcd(q, r);
	}
