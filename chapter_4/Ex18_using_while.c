#include <stdio.h>

int main(void) {
	int cnt = 0, i = -1, j = 0, n, odd_sum = 0, even_sum = 0, error;
	
	while (1) {
		printf("Enter a positive integer: \n");
		scanf("%d", &n);
		if (n <= 0)
		printf("\nError: Do it again\n\n"); 
		break;
		}	
		
	 while (cnt < n) {
		 i += 2 ;
		 j += 2 ;
		odd_sum += i;
		even_sum += j; 
		++cnt; }
						
							
	printf("odd sum: %d even sum %d\n", odd_sum, even_sum);
	return 0;
}
/* for (cnt = 0; cnt < n; ++cnt)*/
