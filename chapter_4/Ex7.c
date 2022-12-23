#include <stdio.h>

int main(void) {
	int i;
	
	while (i = 2) {
		printf("Some even numbers: %d %d %d\n", i, i + 2, i + 4);
		i = 0;
	}
	
return 0;
}
