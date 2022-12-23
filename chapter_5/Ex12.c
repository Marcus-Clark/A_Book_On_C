#include <stdio.h>

#define LIMIT 25

int is_prime(int n) ;
int fib(int n);

int main(void) {
	int i;
	

  for (i = 0; i <= LIMIT; ++i) {
	if (is_prime(fib(i)) == 0)
		printf("%d Is not prime %d\n", fib(i), i);
	else printf("%d Is prime %d\n", fib(i), i ); 
}
	
	return 0;
}
	
int is_prime(int n) {
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


/*return fibonacci numbers */

int fib(int n)
{
  int f0 = 0, f1 = 1, temp, i;
  if( n == 0)
    return f0;
  for (i = 2; i <= n; i++)
  {
     temp = f1;
     f1 += f0;
     f0 = temp;
  }
  return f1;
}

