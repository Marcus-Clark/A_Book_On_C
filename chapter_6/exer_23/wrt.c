#include "add.h"

void wrt(cchr *s, int a[])
{
   int   i;

   printf("%s", s);
   /*
   // Print leading zeros as blanks.
   */
   for (i = N - 1; i > 0 && a[i] == 0; --i)
         putchar(' ');
   /*
   // After a leading digit greater than zero is found,
   // print all the remaining digits, including zeros.
   */
   for ( ; i >= 0; --i)
      printf("%d", a[i]);
   putchar('\n');
}
