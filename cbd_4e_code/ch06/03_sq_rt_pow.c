/*
// Square roots and powers are computed.
//
// Remember:
//    On UNIX systems you may need the -lm option
//    when you compile this program.
*/

#include <math.h>
#include <stdio.h>

int main(void)
{
   double   x;

   printf("\n%s\n%s\n%s\n\n",
      "The square root of x and x raised",
      "to the x power will be computed.",
      "---");
   while (1) {                  /* do it forever */
      printf("Input x:  ");
      scanf("%lf", &x);
      if (x >= 0.0)
     printf("\n%15s%22.15e\n%15s%22.15e\n%15s%22.15e\n\n",
          "x = ", x,
          "sqrt(x) = ", sqrt(x),
          "pow(x, x) = ", pow(x, x));
      else
       printf("\nSorry, number must be nonnegative.\n\n");
   }
   return 0;
}
