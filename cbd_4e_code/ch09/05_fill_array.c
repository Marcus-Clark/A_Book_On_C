#include <stdio.h>

#define   M   3     /* number of rows */
#define   N   4     /* number of columns */

int main(void)
{
   int   a[M][N], i, j, sum = 0;

   putchar('\n');
   for (i = 0; i < M; ++i)        /* fill the array */
      for (j = 0; j < N; ++j)
         a[i][j] = i + j;
   for (i = 0; i < M; ++i) {      /* print array values */
      for (j = 0; j < N; ++j)
         printf("a[%d][%d] = %d     ", i, j, a[i][j]);
      printf("\n");
   }
   for (i = 0; i < M; ++i)        /* sum the array */
      for (j = 0; j < N; ++j)
         sum += a[i][j];
   printf("\nsum = %d\n\n", sum);
   return 0;
}
