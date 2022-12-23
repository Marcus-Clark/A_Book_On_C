#include <stdio.h>

int main(void) {
	int n, sum, i;
	
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    if (n > 0) {
		i = n;
			while (i <= 2 * n) {
			sum += i;
			++i;
		}
	} else if (n < 0) /*Note braces around if else multi-line statement */
		i = 2 * n;
			while (i <= n) {
			sum += i;
			++i;
		}

    printf("Sum = %d", sum);
return 0;
}
