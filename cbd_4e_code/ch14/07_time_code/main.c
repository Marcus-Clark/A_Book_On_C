/* Compare multiplication times. */

#include "time_code.h"

int main(void)
{
   long          i;
   float         a, b = 3.333, c = 5.555;                  /*arbitrary values*/
   double        x, y = 3.333, z = 5.555;
   long double   u, v = 3.333, w = 5.555;

   printf("\nNumber of multiplies: %d\n\n", N);
   printf("Type float:\n\n");
   start_time();                                             /* start timing */
   for (i = 0; i < N; ++i)
      a = b * c;
   prn_time();                                            /* print time info */
   printf("Type double:\n\n");
   for (i = 0; i < N; ++i)
      x = y * z;
   prn_time();                                            /* print time info */
   printf("Type long double:\n\n");
   for (i = 0; i < N; ++i)
      u = v * w;
   prn_time();                                            /* print time info */
   prn_total_time();
   return 0;
}
