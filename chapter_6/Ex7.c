#include <stdio.h>

int main(void)
{
	int a = 1, b = 2, c = 3;
	
	printf("%s%lu\n%s%lu\n%s%lu\n",
		"&a = ",(unsigned long) &a,
		"&b = ",(unsigned long) &b,
		"&c = ", (unsigned long)&c);
		
	
	return 0;
	
}
