#include <stdio.h>

int main(void) {
	double a[2], *p, *q;
	
	p = a;		/* points to base of array */
	q = p + 1;	/*equivalent to q = &a[1] */
	printf("%ld\n", q - p); 				/* 1 is printed */
	
	printf("%d\n", (int) q - (int) p);	/* 8 is printed */
	
	return 0; 
}
	

