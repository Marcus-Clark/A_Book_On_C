#include "majority.h"

void prn_results(short a, short b, short c, short majority)
{
   char*   s;
   int     i;
   int     mask = 1 << 15;                                    // mask = 100...0

   cout << "\n"
           "          a = " << bit_print(a) << "\n"
           "          b = " << bit_print(b) << "\n"
           "          c = " << bit_print(c) << "\n"
           "\n"
           "   majority = " << bit_print(majority) << "\n"
           "\n";
   for (i = 0; i < 16; ++i) {
      s = (((majority << i) & mask) != 0) ? "pass" : "fail";
      cout << "   Referendum " << setw(2) << i + 1 << ": " << s << "\n";
   }
   cout << "\n";
}
