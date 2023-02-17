#include <stdio.h>

int main(void)
{
   char            c  = 128;       /* turn the high bit on */
   signed char     sc = 128;
   unsigned char   uc = 128;

   printf("\nc = %d  sc = %d  uc = %d\n\n", c, sc, uc);
   return 0;
}
