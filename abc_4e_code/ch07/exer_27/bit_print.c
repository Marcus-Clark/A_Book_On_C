/* Bit print an int expression. */

#include <limits.h>

void bit_print(int a)
{
   int   i;
   int   n = sizeof(int) * CHAR_BIT;       /* in limits.h */
   int   mask = 1 << (n - 1);              /* mask = 100...0 */

   for (i = 1; i <= n; ++i) {
      putchar(((a & mask) == 0) ? '0' : '1');
      a <<= 1;
      if (i % CHAR_BIT == 0 && i < n)
         putchar(' ');
   }
}
