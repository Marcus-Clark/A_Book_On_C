#include "trace.h"

dbl ***get_tensor_space(int m, int n, int p)
{
   int   i;
   int   j;
   dbl   *base1;
   dbl   **base2;
   dbl   ***a;

   assert(m > 0);
   assert(n > 0);
   assert(p > 0);
   /*
   // Get the space for the elements
   // of the tensor all at once.
   */
   base1 = malloc(m * n * p * sizeof(dbl));
   /*
   // Get the space for the elements of the
   // tensor slices [matrices] all at once.
   */
   base2 = malloc(m * n * sizeof(dbl *));
   /*
   // List of types:
   //
   //    a            has type dbl ***
   //    a[i]         has type dbl **
   //    a[i][j]      has type dbl *
   //    a[i][j][k]   has type dbl
   */
   a = malloc(m * sizeof(dbl **));
   assert(base1 != NULL);
   assert(base2 != NULL);
   assert(a != NULL);
   /*
   // Offset pointers to change the indexing.
   */
   --a;                                         /* index from 1, not 0 */
   for (i = 1; i <= m; ++i) {
      a[i] = base2 + ((i - 1) * n * p) - 1;     /* index from 1, not 0 */
      for (j = 1; j <= n; ++j)
         /*
         // The next line is wrong!
         */
         a[i][j] = base1 + ((i * j - 1) * p) - 1;             /* ditto */
   }
   return a;
}

void release_tensor_space(dbl ***a)
{
   dbl   *base1;
   dbl   **base2;

   /*
   // The effects of offsetting the pointers
   // must be undone before releasing space.
   */
   base2 = a[1] + 1;
   base1 = a[1][1] + 1;
   free(base1);
   free(base2);
   free(a);
}
