#include <stdio.h>
#include <ctype.h>

#define MAXSTRING 100

int main(void) {
	char 	c, name[MAXSTRING];
	int 	i, sum = 0;
	
	printf("Hi, what is your name?  ");
	for (i = 0; (c=getchar()) != '\n'; ++i) {
		name[i]  = c;
		if (isalpha(c))
		sum += c;
	}
	name[i] = '\0';
	printf("\n%s", 
			"Your name spelled backward is ");
	for (--i; i >= 0; --i)
		putchar(name[i]);
	printf("\n%s%d",
		"and the letters in your name sum to ", sum);
		return 0;
	}
	
	
