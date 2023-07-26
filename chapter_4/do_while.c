#include <stdio.h>
#include <ctype.h>
int main(void) {

int n, error;


do {
	printf("Input a positive integer:  ");
	scanf("%d", &n);
	if (error = (n <= 0))
		if (error = (!isdigit(n)))
			printf("\nError: Do it again!\n\n");
	} while (error);
		

return 0;

}
