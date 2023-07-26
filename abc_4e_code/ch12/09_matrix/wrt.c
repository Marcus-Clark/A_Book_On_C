#include "trace.h"

void wrt_info(cchr *pgm_name)
{
   printf("%s%s%s\n",
      "---\n"
      "Usage:  ", pgm_name, " [-h]\n"
      "\n"
      "This program creates space for an mxn matrix A, fills the matrix A\n"
      "with randomly distributed integers from -9 to +9, and then prints\n"
      "the matrix A along with the value of its trace.\n"
      "\n"
      "---\n"
      "Options:\n"
      "   -h   help option, print this message\n");
}

void wrt_matrix(cchr *s, dbl **a, int m, int n)
{
   int   i, j;

   printf("%s =\n", s);
   for (i = 1; i <= m; ++i) {
      for (j = 1; j <= n; ++j)
         printf("%6.1f", a[i][j]);
      putchar('\n');
   }
   putchar('\n');
}
