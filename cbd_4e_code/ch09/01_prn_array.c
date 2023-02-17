#include <stdio.h>

#define   N   5

int main(void)
{
   int   a[N];             /* allocate space for a[0] to a[4] */
   int   i, sum = 0;

   for (i = 0; i < N; ++i)                  /* fill the array */
      a[i] = 7 + i * i;
   for (i = 0; i < N; ++i)                 /* print the array */
      printf("a[%d] = %d    ", i, a[i]);
   for (i = 0; i < N; ++i)                /* sum the elements */
      sum += a[i];
   printf("\nsum = %d\n", sum);              /* print the sum */
   return 0;
}
