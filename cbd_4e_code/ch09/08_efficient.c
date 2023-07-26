/* Compute various statistics more efficiently. */

#include <stdio.h>

typedef   double   dbl;

void   stats(dbl *, int, dbl *, dbl *, dbl *);

#define   N   10

int main(void)
{
   int   i;
   dbl   a[N], average, max, sum;

   printf("\nInput %d numbers:  ", N);
   for (i = 0; i < N; ++i)
      scanf("%lf", &a[i]);
   stats(a, N, &average, &max, &sum);
   printf("\n%s%5d\n%s%7.1f\n%s%7.1f\n%s%7.1f\n\n",
      "     Array size:", N,
      "Maximum element:", max,
      "        Average:", average,
      "            Sum:", sum);
   return 0;
}

void stats(dbl a[], int n, dbl *p_average, dbl *p_max, dbl *p_sum)
{
   int   i;

   *p_max = *p_sum = a[0];
   for (i = 1; i < n; ++i) {
      *p_sum += a[i];
      if (*p_max < a[i])
       *p_max = a[i];
   }
   *p_average = *p_sum / (dbl) n;
}
