#include <stdio.h>

int main(void) {
	
	int i, n, total;
	
	 i = -5;
	 n = 50;
	 while (i < n) {
		 ++i;
		/*if (i == 0)
			continue; */
		total += i;
		printf("i = %d and total = %d\n", i, total);
	}
return 0;
}
