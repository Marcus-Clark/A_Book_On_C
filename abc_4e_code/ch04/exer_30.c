#include <stdio.h>

int main(void)
{
   int      cnt;
   double   a, x0, x1;

   printf("Newton's method will be used to find square roots.\n\n");
   for ( ; ; ) {
      printf("Input a positive number: ");
      scanf("%lf", &a);
      cnt = 0;
      x0 = 0.0;
      x1 = 1.0;
      while (x1 != x0) {
         ++cnt;
         x0 = x1;                     /*  save the current value of  x1  */
         x1 = .5 * (x1 + a / x1);     /*  compute a new value of  x1  */
      }
      printf("%g %g %g %d\n", a, x1, a - x1 * x1, cnt);
   }
   return 0;
}
