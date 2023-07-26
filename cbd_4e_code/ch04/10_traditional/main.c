/* Print a table of square roots. */

#include <stdio.h>

double   sqrt();          /* traditional C style */

int main()
{
   int   i;

   for (i = 1; i < 20; ++i)
      printf("%5d:%7.3f\n", i, sqrt(i));
   return 0;
}
