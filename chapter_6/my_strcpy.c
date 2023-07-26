#include <stdio.h>

char *strcpy(char *s1, register const char *s2);
int main(void) {
	
	char s1[] = "He";
	char s2[] = "world";
	
	printf("%s\n", strcpy(s1, s2));
	
	return 0;
}

char *strcpy(char *s1, register const char *s2) 
{
	register char	*p = s1;
	
	while ((*p++ = *s2++))
		;
	return s1;
}
