// ---
// Bit print an int expression.
//

#include "try_me.h"

cchr* bit_print(int a)
{
   int          i;
   int          n = sizeof(int) * CHAR_BIT;                      // in limits.h
   int          mask = 1 << (n - 1);                          // mask = 100...0
   ostrstream   oss;

   for (i = 1; i <= n; ++i) {
      oss << (((a & mask) == 0) ? '0' : '1');
      a <<= 1;
      // if (i % CHAR_BIT == 0 && i < n)
         // oss << ' ';
   }
   oss << ends;
   return oss.str();
}
