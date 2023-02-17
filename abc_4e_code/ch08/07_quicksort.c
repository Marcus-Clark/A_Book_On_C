/* Quicksort!  Pointer version with macros. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define   N   300

#define   swap(x, y)    { int t; t = x; x = y; y = t; }
#define   order(x, y)   if (x > y) swap(x, y)
#define   o2(x, y)      order(x, y)
#define   o3(x, y, z)   o2(x, y); o2(x, z); o2(y, z)

typedef   enum {yes, no}   yes_no;

static yes_no   find_pivot(int *left, int *right, int *pivot_ptr);
static int      *partition(int *left, int *right, int pivot);
void            quicksort(int *, int *);

int main(void)
{
   int   a[N], i;

   srand(time(NULL));
   for (i = 0; i < N; ++i)
      a[i] = rand() % 1000;
   quicksort(a, a + N - 1);
   for (i = 0; i < 7; ++i)
      printf("%4d", a[i]);
   printf(" .....");
   for (i = N - 8; i < N; ++i)
      printf("%4d", a[i]);
   putchar('\n');
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

void quicksort(int *left, int *right)
{
   int   *p, pivot;

   if (find_pivot(left, right, &pivot) == yes) {
      p = partition(left, right, pivot);
      quicksort(left, p - 1);
      quicksort(p, right);
   }
}
