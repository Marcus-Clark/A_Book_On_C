#include <stdio.h>
#define MAXSTRING 100
void wrt_it(void);

int main(void) {
	
	printf("Input a line: ");
	wrt_it();
	printf("\n\n");
	
	
	return 0;
}

void wrt_it(void) {
	
	int i, c;
	char string[MAXSTRING];
	for (i = 0; (c = getchar()) != '\n'; ++i)  
		string[i] = c;
			for (--i; i >=0; --i)
				putchar(string[i]);
	
	}
