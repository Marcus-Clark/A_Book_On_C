#include "primes.h"

int is_prime(int n)
{
   int   k, limit;

   if (n == 2)
      return 1;
   if (n % 2 == 0)
      return 0;
   limit = n / 2;
   for (k = 3; k <= limit; k += 2)
      if (n % k == 0)
         return 0;
   return 1;
}
