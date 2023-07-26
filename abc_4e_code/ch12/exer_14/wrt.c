#include "trace.h"

void wrt_info(cchr *pgm_name)
{
   printf("%s%s%s\n",
      "---\n"
      "Usage:  ", pgm_name, " [-h]\n"
      "\n"
      "This program creates space for an m x n x p tensor A, fills it\n"
      "with randomly distributed digits from -9 to +9, and then prints\n"
      "the tensor A and its trace.\n"
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

void wrt_tensor(cchr *s, dbl ***a, int m, int n, int p)
{
   char   str[MAXSTRING];
   int    i;

   printf("Slices of %s:\n\n", s);
   for (i = 1; i <= m; ++i) {
      sprintf(str, "%s[%d]", s, i);
      wrt_matrix(str, a[i], n, p);
   }
}
