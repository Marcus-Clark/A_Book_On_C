
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
    int upper, lower;

    printf("Enter lower limit: ");
    if (scanf("%d", &lower) != 1)
        return 1;

    printf("Enter upper limit: ");
    if (scanf("%d", &upper) != 1)
        return 1;

    for (int n = lower; n <= upper; n += 2) {
        for (int i = 1; i <= n / 2; i++) {
            if (isprime(i) && isprime(n - i)) {
                printf("%d = %d + %d\n", n, i, n - i);
                break;
            }
        }
    }
    return 0;
}          

