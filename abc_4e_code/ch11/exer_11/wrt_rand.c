#include "wrt_rand.h"

void wrt_rand(FILE *ofp, int n)
{
   int   i;

   assert(ofp != NULL);
   for (i = 1; i <= n; ++i) {
      fprintf(ofp, "%12d", rand());
      if (i % 6 == 0 || i == n)
         fprintf(ofp, "\n");
   }
}
