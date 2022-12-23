#include <stdio.h>

char *my_strcat(char *s1, register const char *s2);
int main(void) {
	
	char s1[10] = "Hello";
	char s2[] = "world";
	
	printf("%s\n", my_strcat(s1, s2));
	
	return 0;
}

char *my_strcat(char *s1, register const char *s2) 
{
	register char	*p = s1;
	


	while (*p != '\0') {
		++p;
				
	}
	
		
	while ((*p++ = *s2++))
		;
		
	return s1;
}
