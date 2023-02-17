#include "cmp_sorts.h"

void chk_arrays(int *a, int *b, int n)
{
   int   i;

   for (i = 0; i < n - 1; ++i) {
      assert(a[i] == b[i]);
      assert(a[i] <= a[i+1]);
   }
   assert(a[i] == b[i]);
}
