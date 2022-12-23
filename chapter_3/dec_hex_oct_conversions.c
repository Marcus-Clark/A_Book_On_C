#include <stdio.h>

int main(void) {
	printf("dec	hex	oct\n");
	printf("%d	%x	%o\n", 19, 19, 19); /*19 23 23 */
	printf("%d	%x	%o\n", 0x1c, 0x1c, 0x1c);
	printf("%d	%x	%o\n", 017, 017, 017);
	
	
	return 0;
}
