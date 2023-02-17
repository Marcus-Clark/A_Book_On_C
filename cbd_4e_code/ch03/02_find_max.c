/* Find the maximum of n real values. */

#include <stdio.h>

int main(void)
{
   int     cnt = 0, n;
   float   max, x;

   printf("The maximum value will be computed.\n");
   printf("How many numbers do you wish to enter?  ");
   scanf("%d", &n);
   while (n <= 0) {
      printf("\nERROR: Positive integer required.\n\n");
      printf("How many numbers do you wish to enter?  ");
      scanf("%d", &n);
   }
   printf("\nEnter %d real numbers:  ", n);
   scanf("%f", &x);
   max = x;
   while (++cnt < n) {
      scanf("%f", &x);
      if (max < x)
       max = x;
   }
   printf("\nMaximum value:  %g\n", max);
   return 0;
}
