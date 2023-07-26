#include <limits.h>           /* for UINT_MAX */
#include <stdio.h>

int main(void)
{
   int        i;
   unsigned   u = UINT_MAX;   /* typically 4294967295 */

   for (i = 0; i < 10; ++i)
      printf("%u + %d = %u\n", u, i, u + i);
   for (i = 0; i < 10; ++i)
      printf("%u * %d = %u\n", u, i, u * i);
   return 0;
}
