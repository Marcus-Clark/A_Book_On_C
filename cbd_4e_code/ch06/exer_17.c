/*
// Modular arithmetic on the integral types.
*/

#include <stdio.h>
#include <limits.h>     /* for UINT_MAX */

int main(void)
{
   int        i;
   unsigned   u = UINT_MAX;

   printf("\nThe largest unsigned int is %u\n\n", u);
   for (i = 0; i < 10; ++i)
      printf("%u + %d = %u\n", u, i, u + i);
   for (i = 0; i < 10; ++i)
      printf("%u * %d = %u\n", u, i, u * i);
   return 0;
}
