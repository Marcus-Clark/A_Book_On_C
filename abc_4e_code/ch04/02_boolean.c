/* Print a table of values for some boolean functions. */

#include <stdio.h>

int main(void)
{
   int   b1, b2, b3, b4, b5;             /* boolean variables */
   int   cnt = 0;

   printf("\n%5s%5s%5s%5s%5s%5s%7s%7s%11s\n\n",   /* headings */
      "Cnt", "b1", "b2", "b3", "b4", "b5",
      "fct1", "fct2", "majority");

   for (b1 = 0; b1 <= 1; ++b1)
      for (b2 = 0; b2 <= 1; ++b2)
         for (b3 = 0; b3 <= 1; ++b3)
            for (b4 = 0; b4 <= 1; ++b4)
               for (b5 = 0; b5 <= 1; ++b5)
                  printf("%5d%5d%5d%5d%5d%5d%6d%7d%9d\n",
                     ++cnt, b1, b2, b3, b4, b5,
                     b1 || b3 || b5, b1 && b2 || b4 && b5,
                     b1 + b2 + b3 + b4 + b5 >= 3);
   putchar('\n');
   return 0;
}
