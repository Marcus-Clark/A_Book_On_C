#include "trace.h"

void fill_tensor(dbl ***a, int m, int n, int p)
{
   int   i, j, k;

   for (i = 1; i <= m; ++i)
      for (j = 1; j <= n; ++j)
         for (k = 1; k <= p; ++k)
            a[i][j][k] = rand() % 19 - 9;             /* from -9 to +9 */
}
