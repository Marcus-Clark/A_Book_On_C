/* Print Fibonacci numbers and quotients. */

#include <stdio.h>

#define   LIMIT   46

int main(void)
{
   long   f0 = 0, f1 = 1, n, temp;

   printf("%7s%19s%29s\n%7s%19s%29s\n%7s%19s%29s\n",   /* headings */
      "  ", "Fibonacci", "Fibonacci",
      " n", "   number", " quotient",
      "--", "---------", "---------");
   printf("%7d%19d\n%7d%19d\n", 0, 0, 1, 1);    /* first two cases */

   for (n = 2; n <= LIMIT; ++n) {
      temp = f1;
      f1 += f0;
      f0 = temp;
      printf("%7ld%19ld%29.16f\n", n, f1, (double) f1 / f0);
   }
   return 0;
}
