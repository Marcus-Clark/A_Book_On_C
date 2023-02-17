#include "trace.h"

dbl trace(dbl **a, int m, int n)
{
   int   i;
   int   k;
   dbl   sum = 0.0;

   k = (m < n) ? m : n;
   for (i = 1; i <= k; ++i)
      sum += a[i][i];
   return sum;
}
