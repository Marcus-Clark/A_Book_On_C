#include <stdio.h>

int main(void) {
	int *p, a = 1;
	
	p = &a;
	
	printf("%d\n", *p); 
	
	return 0;
}
