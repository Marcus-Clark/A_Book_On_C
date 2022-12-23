#include <stdio.h>

size_t strlen(const char *s);
int main(void) {
	
	const char s[] = "0123";
	
	printf("string length is: %lu\n",strlen(s));
	
	return 0;
}

size_t strlen(const char *s)
{
	size_t 	n;
	
	for (n = 0; *s != '\0'; ++s)
		++n;
	return n;
}
