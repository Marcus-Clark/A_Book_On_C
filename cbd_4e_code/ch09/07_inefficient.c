/* Compute various statistics. */

#include <stdio.h>

#define   N   10                   /* size of the array */

double   average(double *, int);
double   maximum(double *, int);
double   sum(double *, int);

int main(void)
{
   int      i;
   double   a[N];

   printf("\nInput %d numbers:  ", N);
   for (i = 0; i < N; ++i)
      scanf("%lf", &a[i]);
   printf("\n%s%5d\n%s%7.1f\n%s%7.1f\n%s%7.1f\n\n",
      "     Array size:", N,
      "Maximum element:", maximum(a, N),
      "        Average:", average(a, N),
      "            Sum:", sum(a, N));
   return 0;
}

double average(double a[], int n)
{
   return (sum(a, n) / (double) n);
}

double maximum(double a[], int n)
{
   int      i;
   double   max = a[0];

   for (i = 0; i < n; ++i)
      if (max < a[i])
         max = a[i];
   return max;
}

double sum(double a[], int n)
{
   int      i;
   double   s = 0.0;

   for (i = 0; i < n; ++i)
      s += a[i];
   return s;
}
