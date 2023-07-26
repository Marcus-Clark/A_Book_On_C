#include <stdio.h>

void factor(int num);
int isprime(int n);

int main(void) {
	
	 int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("%d = ", num);
    factor(num);
      

    return 0;
}
void factor(int num) {
int i;

for (i = 2; num > 1; ++i)
    {
    while ((num % i == 0 && isprime(i) == 1) ) {
		printf("%d x ", i);
		num = num / i; 
		}		
	}

	
}

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
