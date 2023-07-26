#include <stdio.h>

int main(void) {
	int cnt = 0, i = -1, j = 0, n, odd_sum = 0, even_sum = 0;
	
	printf("Enter a number: \n");
	scanf("%d", &n);
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
