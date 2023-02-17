#include "trace.h"

dbl **get_matrix_space(int m, int n)
{
   int   i;
   dbl   *p;
   dbl   **a;

   p = malloc(m * n * sizeof(dbl));       /* get the space all at once */
   a = malloc(m * sizeof(dbl *));
   assert(p != NULL);
   assert(a != NULL);
   /*
   // Offset pointers to change the indexing.
   */
   --a;                                         /* index from 1, not 0 */
   for (i = 1; i <= m; ++i)
      a[i] = p + ((i - 1) * n) - 1;             /* index from 1, not 0 */
   return a;
}

void release_matrix_space(dbl **a)
{
   dbl   *p;

   /*
   // The effects of offsetting the pointers
   // must be undone before releasing space.
   */
   p = a[1] + 1;                             /* base address in memory */
   free(p);
   free(a + 1);
}
