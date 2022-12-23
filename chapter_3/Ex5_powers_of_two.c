#include <stdio.h>

int main(void) {
int i, val = 1;
	printf("dec,        dec,         hex,           oct\n");
for (i = 1; i < 32; ++i) {
	printf("%15d%15u%15x%15o\n", val, val, val, val);
	val *= 2;
}
return 0;
}
