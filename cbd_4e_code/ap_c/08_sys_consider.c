//
// ---
// This program illustrates the expressions
// in the table on page 635 of the text.
//

#include <iostream.h>
#include <limits.h>
#include <strstream.h>

typedef   const char   cchr;

cchr*   bit_print(int a);

int main()
{
   cout << "\n"
           "---\n"
           "With signed types, the sign bit gets propogated:\n"
           "\n"
           "                   128 = " << bit_print(128)                 << "\n"
           "            (char) 128 = " << bit_print((char) 128)          << "\n"
           "           (short) 128 = " << bit_print((short) 128)         << "\n"
           "                 32768 = " << bit_print(32768)               << "\n"
           "         (short) 32768 = " << bit_print((short) 32768)       << "\n"
           "              -1 ^ 128 = " << bit_print(-1 ^ 128)            << "\n"
           "     (char) (-1 ^ 128) = " << bit_print((char) (-1 ^ 128))   << "\n"
           "                   255 = " << bit_print(255)                 << "\n"
           "   (unsigned char) 255 = " << bit_print((unsigned char) 255) << "\n"
           "     (signed char) 255 = " << bit_print((signed char) 255)   << "\n"
           "            (char) 255 = " << bit_print((char) 255)          << "\n"
           "\n";
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
