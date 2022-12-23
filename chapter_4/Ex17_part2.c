#include <stdio.h>

int main(void) {
	int cnt, i, j, n, odd_sum, even_sum;
	/*use two for loops, one for even, one for odd
	 * split n using if (n % 2 == 0) for even
	 * 				 else {......} for odd */
	printf("Enter a number: \n");
	scanf("%d", &n);
	if (n % 2 == 0) {
		for (j = 2; cnt < n ;  j += 2 )
			for (cnt = 0; cnt < n; ++cnt)
				even_sum += j;
	printf("even sum: %d\n", even_sum);
} else 
		for (i = 1; cnt < n ;  i += 2 )
			for (cnt = 0; cnt < n; ++cnt)
				odd_sum += i;
	printf("odd sum: %d\n", odd_sum);
	return 0;
}
/*for (cnt = 0,  j = 2; cnt < n; ++cnt, j+=2 ) */
