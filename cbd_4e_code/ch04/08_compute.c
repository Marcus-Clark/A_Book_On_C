#include <stdio.h>

int   compute_sum(int n);

int main(void)
{
   int   n = 3, sum;

   printf("n = %d\n", n);                 /* 3 is printed */
   sum = compute_sum(n);
   printf("n = %d\n", n);                 /* 3 is printed */
   printf("sum = %d\n", sum);             /* 6 is printed */
   return 0;
}

int compute_sum(int n)            /* sum ints from 1 to n */
{
   int   sum = 0;

   for ( ; n > 0; --n)       /* in main(), n is unchanged */
      sum += n;
   printf("n = %d\n", n);                 /* 0 is printed */
   return sum;
}
