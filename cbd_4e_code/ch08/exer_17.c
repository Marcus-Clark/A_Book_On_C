#include <stdio.h>

int main(void)
{
   const float   x = 7.7;
   float         *p = &x;     /* compiler error or warning? */

   printf("x = %g\n", *p);
   return 0;
}
