#include <stdio.h>

int main(void) {
	int *p;
	float *q;
	void *v;
	
	p = v = q;
	
	printf("%d\n", p);
	return 0;
}
