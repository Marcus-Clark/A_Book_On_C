#include <stdio.h>
#include <ctype.h>

char *my_strcpy(char *dest, register const char *source);

int main(void) {
	
	char *source = "This is the string to copy";
	char dest[100] = "Copy to here";
	
	
	printf("%s\n", my_strcpy(dest, source));
	return 0;
}

/* *my_strcpy: a function to copy string source to string dest */

char *my_strcpy(char *dest, register const char *source) {
	register char *p = dest;
	
	while ( (*p++ = *source++) )
		;
	return dest;
}
