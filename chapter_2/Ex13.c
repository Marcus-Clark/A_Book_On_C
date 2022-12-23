#include <stdio.h>

/*int main(void) {
	
	int		i, power = 2048;
	
	for (i = 10 ; i > 0; --i) 
		
	printf("%-6d", power /= 2);
	return 0;
} */

int main(void) {
	
	int		 power = 2048;
	
	while ((power /= 2) > 0)
		printf("%-6d", power);
	return 0;
}
