#include <stdio.h>

int hailstone(int n);

int main(void) {
	int start;

 printf("Input a number: ");
 scanf("%d", &start);
 while (start != 1) 
 {
	 start = hailstone(start);
	 printf("%d\n", start);
 }
	
	return 0;
}

int hailstone(int n) {
	
	if (n % 2 == 0) {
		return n / 2 ;
	}
	else {
		return (3 * n) + 1;
	}
}

	
