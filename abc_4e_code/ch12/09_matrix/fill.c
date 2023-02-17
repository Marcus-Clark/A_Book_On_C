#include "trace.h"

void fill_matrix(dbl **a, int m, int n)
{
   int   i, j;

   for (i = 1; i <= m; ++i)
      for (j = 1; j <= n; ++j)
         a[i][j] = rand() % 19 - 9;                   /* from -9 to +9 */
}
