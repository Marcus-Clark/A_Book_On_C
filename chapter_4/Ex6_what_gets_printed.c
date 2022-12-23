#include <stdio.h>

int main(void) {
	
	char c = 'A';
	int i = 5, j = 10;
	
	printf("%d %d %d\n", !c, !!c, !!!c);
	printf("%d %d %d\n", - ! i, ! - i, ! - i - ! j);
	printf("%d %d %d\n", ! (6 * j + i -c), ! i-5, ! j - 10);
return 0;
}
