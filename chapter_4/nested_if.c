#include <stdio.h>

int main(void) {
	int a, b;
	a = 1;
	b = 2;
	
	if (a == 1)		/* we need this to be true for anything below to happen */
		if (b ==2)
			printf("***\n");
		else
			printf("###\n");
	return 0;
}
