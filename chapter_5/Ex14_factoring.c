#include <stdio.h>

int isprime(int n)
{
    if (n == 2 || n == 3)
        return 1;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return 0;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }

    return 1;
}  

int main(void) {
	
	 int num, i = 1;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Factors of %d are: ", num);
    
    while (i <= num) {
		if (num % i == 0 && isprime(i) == 1) {
		printf("%d ", i);
	}
		++i;
	}
	printf("\n"); 
    /*for ( ; i <= num; ++i) {
        if (num % i == 0 && isprime(i) == 1) {
            printf("%d ", i); */
      

    return 0;
}

