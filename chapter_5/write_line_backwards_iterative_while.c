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
	
	i = 0;
	while ((c = getchar()) != '\n') {
		string[i] = c;
		++i;
	}
	while (i >= 0) {
		putchar(string[i]);
		--i;
		}
			
	}
