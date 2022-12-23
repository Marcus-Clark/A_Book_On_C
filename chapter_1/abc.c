#include <stdio.h>
#include <string.h>

#define MAXSTRING 100

int main(void) {
	char c = 'a', *p, s[MAXSTRING];
	char b = 't', *z;
	p = &c;
	z = &b;
	
	printf("%c%c%c\n", *p + 25, *p + 14, *p + 14);
	printf("%c%c%c\n", *z, *p + 14, *p + 14);
	
	strcpy(s, "ABC");
	printf("%s %c%c%s\n\n", s, *s - 1, *s + 24, s + 3);
	
	strcpy(s, "she sells sea shells by the sea shore");
	p = s + 14;
	for ( ; *p != '\0'; ++p) {
		if (*p == 'e')
			*p = 'E';
		if (*p == ' ')
			*p = '\n';
		}
		printf("%s\n", s);
		strcpy(s, "she sells sea shells by the sea shore");
		printf("%c\n", *(s + 15)); /* s[i] and *(s + i) are equivalent */
		printf("%c\n", s[15]);
	return 0;
}
