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
	
	 int num, i ;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Factors of %d are: ", num);
    for (i = 2; num > 1; i++)
    {
    while ((num % i == 0 && isprime(i) == 1) ) {
		printf("%d ", i);
		num = num / i; 
		}		
	}
	printf("\n");
      

    return 0;
}

