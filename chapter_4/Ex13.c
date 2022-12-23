#include <stdio.h>

int main(void) {
	int n, sum , i;
	
	printf("Input an integer: ");
	scanf("%d", &n);
	
	if (n > 0)
		for (i=n; i <= 2 * n; ++i)
			sum += i;
	else if (n < 0)
		for (i = (2 * n); i <= n ; ++i)
			sum += i; 
	printf("%d\n", sum);	
	
	
return 0;
}
