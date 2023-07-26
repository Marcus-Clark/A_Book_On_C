#include "add.h"

void add(int sum[], int a[], int b[])
{
   int   carry = 0;
   int   i;

   for (i = 0; i < N; ++i) {
      sum[i] = a[i] + b[i] + carry;
      if (sum[i] < 10)
         carry = 0;
      else {
         carry = sum[i] / 10;
         sum[i] %= 10;
      }
   }
}
