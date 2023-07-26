#include "cmp_sorts.h"

void slow_sort(int *a, int n)
{
   int   i, j, tmp;

   for (i = 0; i < n; ++i)
      for (j = i + 1; j < n; ++j)
         if (a[i] > a[j]) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
         }
}
