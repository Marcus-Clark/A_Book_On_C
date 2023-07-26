#include <stdio.h>
#define N 5

int main(void) {
	
	int i, *p;
	int a[N] = {1, 2, 3, 4, 5};
	p = a;
	for (i = 0; i < N; ++i)
		printf("%d\n", p[i]);
	
	
	return 0;
	
}
