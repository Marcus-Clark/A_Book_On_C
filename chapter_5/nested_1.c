#include <stdio.h>

int main(void) {
int a = 2;
printf("%d\n", a);
	{
		/* int a = 5; */
		printf("inner block a: %d\n", a);
	}
	printf("%d\n", a);
	
	return 0;
}
