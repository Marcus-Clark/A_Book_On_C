#include <stdio.h>

int is_prime(int n) ;

int main(void) {
	int n,  test;
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  test = is_prime(n);
  if ( test == 0)
	printf("Is not prime\n");
  else printf("Is prime\n"); 
  
	
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

