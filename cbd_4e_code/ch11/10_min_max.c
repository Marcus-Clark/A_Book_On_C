/* ---
// The best possible minmax algorithm - Pohl, 1972
//
// The size of the array a[] is n.  In this program n
// must be a power of 2.  The code can be rewritten
// to remove this restriction.
//
// Observe that minmax() is recursive.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int   n = 1024;                                            /* n = 2^10 */

void minmax(int a[], int n, int *min_ptr, int *max_ptr);

int main(void)
{
   int   a[n];
   int   i;
   int   min;
   int   max;

   srand(time(NULL));                    /* seed the random number generator */
   for (i = 0; i < n; ++i)                                 /* fill the array */
      a[i] = rand();
   minmax(a, n, &min, &max);                  /* find the min and max values */
   printf("\n%s%7d%s%7d%s%7d%s",
      "     Max value:", max, "\n"
      "     Min value:", min, "\n"
      "   Size of a[]:", n, "\n"
      "\n");
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
