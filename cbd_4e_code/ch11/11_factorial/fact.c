#include "fact.h"

Integer factorial(int n)
{
   int       i;
   Integer   product = 1;

   for (i = 2; i <= n; ++i)
      product *= i;
   return product;
}
