#include <stdio.h>

int main(void) {
	int c;
	
	while ((c = getchar()) != EOF)
		if (c >= 'a' && c <= 'z')
			putchar(c + 'A' - 'a'); /* 65 - 97 = -32, in ASCII the difference between equivalent upper and lower case is 32.*/
		else
			putchar(c);
	return 0;
	}
			
