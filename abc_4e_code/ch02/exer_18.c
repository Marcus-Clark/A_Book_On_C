#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define   NCALLS    1000000   /* number of fct calls */
#define   NCOLS     10        /* number of columns   */
#define   NLINES    5         /* number of lines     */

int main(void)
{
   int    i, val;
   long   begin, diff, end;

   begin = time(NULL);
   srand(time(NULL));
   printf("\nTIMING TEST: %d calls to rand()\n\n", NCALLS);
   for (i = 0; i < NCALLS; ++i) {
      val = rand();
      if (i < NCOLS * NLINES) {
         if (i % NCOLS == 0)
               putchar('\n');
         printf("%7d", val);
      }
      if (i == NCOLS * NLINES)
         printf("\n.......\n");
   }
   end = time(NULL);
   diff = end - begin;
   printf("%s%ld\n%s%ld\n%s%ld\n%s%.10f\n\n",
      "          end time: ", end,
      "        begin time: ", begin,
      "      elapsed time: ", diff,
      "time for each call: ", (double) diff / NCALLS);
   return 0;
}
