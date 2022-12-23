
#include <stdio.h>

int isprime(int n) {
	int i, flag = 1;
	
	/* 0 and 1 are not prime numbers
     change flag to 0 for non-prime number */
	if (n == 0 || n == 1) {
		flag = 0;
	}
	
    for (i = 2; i <= n/2 ; ++i) {

    /* if n is divisible by i, then n is not prime
       set flag to 0 for non-prime number or 1 for prime number */
    if (n % i == 0) {
      flag = 0;
		break;
		}
	}
return flag;
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

