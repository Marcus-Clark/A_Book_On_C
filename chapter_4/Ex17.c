#include <stdio.h>

int main(void) {
	int cnt, i, j, n, odd_sum, even_sum;
	
	printf("Enter a number: \n");
	scanf("%d", &n);
	
	for (cnt = 0, i = 1, j = 2; cnt < n; ++cnt, i +=2, j+=2)
		odd_sum += i, even_sum += j;
	printf("odd sum: %d even sum: %d\n", odd_sum, even_sum);
	
	return 0;
}
