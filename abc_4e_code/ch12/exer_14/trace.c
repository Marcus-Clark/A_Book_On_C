#include "trace.h"

static int   min(int a, int b, int c);

dbl trace(dbl ***a, int m, int n, int p)
{
   int   i;
   int   k;
   dbl   sum = 0.0;

   k = min(m, n, p);
   for (i = 1; i <= k; ++i)
      sum += a[i][i][i];
   return sum;
}

static int min(int a, int b, int c)
{
   int   val;

   val = (a < b) ? a : b;
   if (c < val)
      val = c;
   return val;
}
