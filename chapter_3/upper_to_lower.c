#include <stdio.h>
/* changes upper case to lower case */
int main(void) {
	int c;
	
	while ((c = getchar()) != EOF)
		if (c >= 'A' && c <= 'Z')
			putchar(c + 'a' - 'A'); /* 97 - 65 = 32. In ASCII the difference between equivalent upper and lower case is 32.*/
		else
			putchar(c);
	return 0;
	}
			
