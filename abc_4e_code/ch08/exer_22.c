/*
// Quicksort!  Pointer version with macros.
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define   swap(x, y)    { int t; t = x; x = y; y = t; }
#define   order(x, y)   if (x > y) swap(x, y)
#define   o2(x, y)      order(x, y)
#define   o3(x, y, z)   o2(x, y); o2(x, z); o2(y, z)

typedef   enum {yes, no}   yes_no;

static yes_no   find_pivot(int *left, int *right, int *pivot_ptr);
static int      *partition(int *left, int *right, int pivot);
static void     quicksort(int *, int *);
static void     wrt(char *s, int *a, int n);

int main(void)
{
   int   *a;
   int   i;
   int   n;                 /* size of the array a[] */

   srand(time(NULL));       /* seed the random number generator */
   printf("%s",
      "---\n"
      "An array of size n will be filled with randomly\n"
      "distributed integers and then sorted.\n");
   for ( ; ; ) {
      printf("\n%s",
         "---\n"
         "Input n: ");
      if (scanf("%d", &n) != 1 || n < 1)
         break;
      assert(n > 0);
      /*
      // Allocate space for the array a[].
      */
      a = malloc(n * sizeof(int));
      assert(a != NULL);
      /*
      // Fill the array.
      */
      for (i = 0; i < n; ++i)
         a[i] = rand() % 1000;
      wrt("Before", a, n);
      /*
      // Sort the array.
      */
      quicksort(a, a + n - 1);
      wrt("After", a, n);
      /*
      // Release the space for the array a[].
      */
      free(a);
   }
   printf("\nBye!\n\n");
   return 0;
}

static yes_no find_pivot(int *left, int *right, int *pivot_ptr)
{
   int   a, b, c, *p;

   a = *left;                                 /* left value */
   b = *(left + (right - left) / 2);        /* middle value */
   c = *right;                               /* right value */
   o3(a, b, c);                     /* order these 3 values */
   if (a < b) {         /* pivot will be higher of 2 values */
      *pivot_ptr = b;
      return yes;
   }
   if (b < c) {
      *pivot_ptr = c;
      return yes;
   }
   for (p = left + 1; p <= right; ++p)
      if (*p != *left) {
       *pivot_ptr = (*p < *left) ? *left : *p;
       return yes;
      }
   return no;           /* all elements have the same value */
}

static int *partition(int *left, int *right, int pivot)
{
   while (left <= right) {
      while (*left < pivot)
       ++left;
      while (*right >= pivot)
       --right;
      if (left < right) {
       swap(*left, *right);
       ++left;
       --right;
      }
   }
   return left;
}

static void quicksort(int *left, int *right)
{
   int   *p, pivot;

   if (find_pivot(left, right, &pivot) == yes) {
      p = partition(left, right, pivot);
      quicksort(left, p - 1);
      quicksort(p, right);
   }
}

static void wrt(char *s, int *a, int n)
{
   int   i;

   printf("\n%s\n%s%s\n", "---", s, ":");
   if (n < 15) {
      for (i = 0; i < n; ++i) {
         if (i % 10 == 0)
            putchar('\n');
         printf("%7d", a[i]);
      }
      if (n % 10 != 0)
         putchar('\n');
   }
   else {
      for (i = 0; i < 3; ++i)
         printf("%7d", a[i]);
      printf("%7s", "...");
      for (i = n / 2 - 1; i <= n / 2 + 1; ++i)
         printf("%7d", a[i]);
      printf("%7s", "...");
      for (i = n - 3; i < n; ++i)
         printf("%7d", a[i]);
      putchar('\n');
   }
}
