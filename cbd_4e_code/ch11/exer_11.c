#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void   minmax(int a[], int n, int *min_ptr, int *max_ptr);

int main(void)
{
   int   *a, i,
         n,                /* n is the size of a[] */
         r_min, r_max,     /* recursive min and max */
         i_min, i_max;     /* iterative min and max */

   srand(time(NULL));      /* seed the random number generator */
   printf("Input a power of 2:  ");
   while (scanf("%d", &n) == 1 && n > 0) {
      a = calloc(n, sizeof(int));
      for (i = 0; i < n; ++i)
         a[i] = rand();
      minmax(a, n, &r_min, &r_max);
      printf("\n%s%d%9s%d\n",
         "recursion:  min = ", r_min, "max = ", r_max);
      i_min = i_max = a[0];
      for (i = 1; i < n; ++i) {
         i_min = (i_min < a[i]) ? i_min : a[i];
         i_max = (i_max > a[i]) ? i_max : a[i];
      }
      printf("%s%d%9s%d\n\n",
         "iteration:  min = ", i_min, "max = ", i_max);
      free(a);
      printf("Input a power of 2:  ");
   }
   return 0;
}

void minmax(int a[], int n, int *min_ptr, int *max_ptr)
{
   int   min1, max1, min2, max2;

   if (n == 2)
      if (a[0] < a[1]) {
         *min_ptr = a[0];
         *max_ptr = a[1];
      }
      else {
         *min_ptr = a[1];
         *max_ptr = a[0];
      }
   else {
      minmax(a, n/2, &min1, &max1);
      minmax(a + n/2, n/2, &min2, &max2);
      if (min1 < min2)
         *min_ptr = min1;
      else
         *min_ptr = min2;
      if (max1 < max2)
         *max_ptr = max2;
      else
         *max_ptr = max1;
   }
}
