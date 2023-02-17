//
// ---
// This program illustrates some common errors using bitwise operators.
// The code is designed for machines with both 2- and 4-byte words.
//

#include <assert.h>
#include <iomanip.h>
#include <iostream.h>
#include <limits.h>
#include <strstream.h>

typedef   const char   cchr;

cchr*   bit_print(int a);

int main()
{
   cchr*      offset          = "                   ";
   int        cb              = CHAR_BIT;                          // char bits
   int        wb              = sizeof(int) * cb;                  // word bits
   long       mask_right      = (long) 1 << (wb - 1);
   long       mask_wrong      = 1 << (wb - 1);

   assert(wb == 16 || wb == 32);

   int        rsa             = (wb == 16) ? 8 : 24;      // right-shift amount
   unsigned   lo_byte_right   = ~((unsigned) 0) >> rsa;
   unsigned   lo_byte_wrong   = ~0 >> rsa;

   cout << "\n"
           "---\n"
           "CONSTANTS:\n"
           "\n"
           "    cb =" << setw(3) << cb  << offset << "// char bits\n"
           "    wb =" << setw(3) << wb  << offset << "// word bits\n"
           "   rsa =" << setw(3) << rsa << offset << "// right-shift amount\n"
           "\n"
           "---\n"
           "MASKS:\n"
           "\n"
           "      mask_right = " << bit_print(mask_right)    << "\n"
           "      mask_wrong = " << bit_print(mask_wrong)    << "\n"
           "   lo_byte_right = " << bit_print(lo_byte_right) << "\n"
           "   lo_byte_wrong = " << bit_print(lo_byte_wrong) << "\n"
           "\n";
   if (wb == 32) {
      cout << "---\n"
              "NOTE:\n"
              "\n"
              "Observe that\n"
              "   \n"
              "   mask_wrong\n"
              "\n"
              "is correct on machines with 4-byte words.  That is,\n"
              "the 1 shows up in the high-order bit as it should.\n"
              "Nonetheless, the code is wrong in the sense that\n"
              "it is not portable.\n"
              "\n"
              "---\n"
              "We tried to simulate what would happen on a machine\n"
              "with 2-byte words by writing\n"
              "\n"
              "\n"
              "   long       mask_wrong      = (short) 1 << (wb - 1);\n"
              "\n"
              "This did not work as we first thought it would.  The\n"
              "reason is subtle:\n"
              "\n"
              "   1             - this expression is of type int\n"
              "   (short) 1     - this expression is also of type int\n"
              "\n"
              "Any char or short, due to integral promotions, gets\n"
              "converted to an int; see page 238 of the text.\n";
      }

}

//
// Bit print an int expression.
//

cchr* bit_print(int a)
{
   int          i;
   int          n = sizeof(int) * CHAR_BIT;                      // in limits.h
   int          mask = 1 << (n - 1);                          // mask = 100...0
   ostrstream   oss;

   for (i = 1; i <= n; ++i) {
      oss << (((a & mask) == 0) ? '0' : '1');
      a <<= 1;
      if (i % CHAR_BIT == 0 && i < n)
         oss << ' ';
   }
   oss << ends;
   return oss.str();
}
