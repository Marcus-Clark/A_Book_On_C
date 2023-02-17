/*
// What gets printed?
*/

#include <stdio.h>

#define   N   100

int main(void)
{
   char   a[N], *p = a;
   int    i;

   for (i = 0; i < N; ++i)
      a[i] = i;

   printf("%d\n", *(p + 3));
   printf("%d\n", *(char *)((int *) p + 3));
   printf("%d\n", *(char *)((double *) p + 3));
   printf("%d\n", *(char *)((long double *) p + 3));
   return 0;
}
