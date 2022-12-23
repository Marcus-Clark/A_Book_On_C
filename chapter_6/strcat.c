#include <stdio.h>

char *my_strcat( char *s1, const char *s2);

int main(void)
{
	char s1[100] = "hello to ";
	char  *s2 = "the world";
	
	printf("%s\n", my_strcat(s1, s2));
	
	return 0;
}
char *my_strcat(char *s1, const char *s2)
{
	
	char *start = s1;
	
	while (*s1 != '\0') {
		++s1;
	}
	
	while (*s2 != '\0') {
		*s1 = *s2;
		++s1;
		++s2;
	}
		*s1 = '\0';
		return start;
	}
		
