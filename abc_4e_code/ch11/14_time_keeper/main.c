/* Compare float and double multiplication times. */

#include "time_keeper.h"

int main(void)
{
   long     i;
   float    a, b = 3.333, c = 5.555;   /* arbitrary values */
   double   x, y = 3.333, z = 5.555;

   printf("Number of multiplies: %d\n\n", N);
   printf("Type float:\n\n");
   start_time();
   for (i = 0; i < N; ++i)
      a = b * c;
   wrt_time();
   printf("Type double:\n\n");
   for (i = 0; i < N; ++i)
      x = y * z;
   wrt_time();
   return 0;
}
