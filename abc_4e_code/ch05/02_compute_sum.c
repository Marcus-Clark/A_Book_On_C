#include <stdio.h>

int main(void)
{
   int   n = 3, sum, compute_sum(int);

   printf("%d\n", n);        /* 3 is printed */
   sum = compute_sum(n);
   printf("%d\n", n);        /* 3 is printed */
   printf("%d\n", sum);      /* 6 is printed */
   return 0;
}

int compute_sum(int n)       /* sum the integers from 1 to n */
{
   int   sum = 0;

   for ( ; n > 0; --n)       /* stored value of n is changed */
      sum += n;
   return sum;
}
