#include "add.h"

int main(void)
{
   int   a[N]    = {7, 5, 9, 8, 9, 7, 5, 0, 0, 9, 9, 0, 8, 8};
   int   b[N]    = {7, 7, 5, 3, 1, 2, 8, 8, 9, 6, 7, 7};
   int   sum[N];
   int   ndigits;

   add(sum, a, b);
   wrt("Integer a: ", a);
   wrt("Integer b: ", b);
   wrt("      Sum: ", sum);
   return 0;
}
