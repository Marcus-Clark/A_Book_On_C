#include "try_me.h"

static const int   k = 32;

void run_run(int n)
{
   int   factor = 1;
   int   i;

   for (i = 0; i <= k; ++i) {
      cout << setw(12) << n << " x "
           << setw(11) << factor << " = "
           << bit_print(n * factor) << "\n";
      factor *= 2;
   }
   cout << "\n";
}
