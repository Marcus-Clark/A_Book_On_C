#include <stdio.h>
/* swap is called by value, */
void swap(int p, int q);

int main(void) {
	int i = 3, j = 5;
	
	swap(i, j);
	printf("%d %d\n", i, j); /* 3	5 is printed */

return 0;
}

void swap(int p, int q)
{
	int tmp;
	
	tmp = p;
	p = q;
	q = tmp;
}
