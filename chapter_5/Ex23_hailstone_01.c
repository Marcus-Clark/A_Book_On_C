#include <stdio.h>

void hailstone(int n);

int main(void) {
	int start;

 printf("Input a number: ");
 scanf("%d", &start);
 hailstone(start);
	
	return 0;
}

void hailstone(int n) {

while (n != 1) {
	if (n % 2 == 0) {
		n=  n / 2 ;
	}
	else {
		n = (3 * n) + 1;
	}
	printf("%d\n", n);
}
	
}

	
