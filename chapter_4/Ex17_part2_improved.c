#include <stdio.h>

int main(void) {
	int cnt, i = -1, j = 0, n, odd_sum = 0, even_sum = 0;
	
	printf("Enter a number: \n");
	scanf("%d", &n);
	for (cnt = 0; cnt < n; ++cnt) {
		 i += 2 ;
		 j += 2 ;
		odd_sum += i;
		even_sum += j; } 
						
							
	printf("odd sum: %d even sum %d\n", odd_sum, even_sum);
	return 0;
}
/*for (cnt = 0,  j = 2; cnt < n; ++cnt, j+=2 ) */
