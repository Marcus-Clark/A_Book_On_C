#include "majority.h"

void chk(short a, short b, short c, short majority)
{
   int      cnt;
   int      i;
   int      mask        = 1 << 15;                            // mask = 100...0
   no_yes   print_all   = no;

   if (print_all == yes)
      cout << "   mask = " << bit_print(mask) << "\n\n";
   for (i = 0; i < 16; ++i) {
      cnt =   (((a << i) & mask) != 0)
            + (((b << i) & mask) != 0)
            + (((c << i) & mask) != 0);
      assert(cnt >=0 && cnt <= 3);
      if (print_all == yes) {
         cout << "   i =" << setw(3) << i << "   cnt = " << cnt
              << "   ((majority << " << setw(2) << i << ") & mask) = "
              << bit_print((majority << i) & mask) << "\n";
      }
      if (cnt == 0 || cnt == 1)
         assert((((majority << i) & mask) != 0) == 0);
      if (cnt == 2 || cnt == 3)
         assert((((majority << i) & mask) != 0) == 1);
   }
   if (print_all == yes)
      cout << "\n";
}

//
// The function rand() returns randomly distributed
// integers in the interval [0, MAX_RAND], and on
// most C systems, MAX_RAND has the value 32767.
//
// We need to get values that turn on the high-order
// bits, as well as the low-order bits, of a short.
//

short vote()
{
   int   val;

   val = rand();
   if (val % 2 == 0)
      return -val;
   return val;
}
