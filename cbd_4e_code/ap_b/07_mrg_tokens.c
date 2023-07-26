#include <stdio.h>

#define   X(i)   x ## i

int main(void)
{
   int   sum, x1, x2, x3;

   X(1) = X(2) = X(3) = 333;
   sum = X(1) + X(2) + X(3);
   printf("\n   sum = %d\n\n", sum);
   return 0;
}
