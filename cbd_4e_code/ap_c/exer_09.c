/*
// ---
// Exercise 9 on page 639:
//
// Determine whether sign bits get shifted in.
*/

#include <stdio.h>

int main(void)
{
   int        i = -1;     /* turn all bits on */
   unsigned   u = -1;

   if (i >> 1 == u >> 1)
      printf("\nZeros are shifted in.\n\n");
   else
      printf("\nSign bits are shifted in.\n\n");
   return 0;
}
