#include "quicksort.h"

int main(void)
{
   int    a[N], i;

   srand(time(NULL));
   for (i = 0; i < N; ++i)
      a[i] = rand() % 10000;
   quicksort(a, a + N - 1);
   /*
   // Check that the array a[] has been sorted
   // but do not print the array.  We want to
   // profile the sorting, not the printing.
   */
   for (i = 0; i < N - 1; ++i) {
      if (a[i] > a[i + 1]) {
       printf("SORTING ERROR - bye!\n");
       exit(1);
      }
   }
   return 0;
}
