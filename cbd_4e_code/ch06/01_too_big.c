#include <stdio.h>

#define   BIG   2000000000     /* 2 billion */

int main(void)
{
   int   a, b = BIG, c = BIG;

   a = b + c;                         /* out of range? */

   printf("\n%s%d\n%s%d\n\n%s%d\n\n",
      "   b = ", b,
      "   c = ", c,
      "   a = b + c = ", a);

   return 0;
}
