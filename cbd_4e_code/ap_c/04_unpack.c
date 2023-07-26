//
// ---
// This program tests the pack() and unpack() functions.
//
// These version of pack() and unpack() only work on machines
// with 4-byte words.  The output is machine-dependent.
//

#include <assert.h>
#include <iostream.h>
#include <limits.h>
#include <strstream.h>

typedef   const char   cchr;

cchr*   bit_print(int a);
int     pack(char a, char b, char c, char d);
char    unpack(int p, int k);

int main()
{
   const int   cb      = CHAR_BIT;                               // in limits.h
   const int   wb      = sizeof(int) * cb;                         // word bits
   const int   mask1   = 1 << (wb - 1);                      // mask1 = 100...0
   const int   mask2   = 255;                             // the low-order byte
   const int   n0      = 0 * cb;
   const int   n1      = 1 * cb;
   const int   n2      = 2 * cb;
   const int   n3      = 3 * cb;
   int         a1      = 11;
   int         a2      = 22;
   int         a3      = 33;
   int         a4      = 44;
   int         pkg     = pack(a1, a2, a3, a4);
   int         b1      = unpack(pkg, 3);
   int         b2      = unpack(pkg, 2);
   int         b3      = unpack(pkg, 1);
   int         b4      = unpack(pkg, 0);

   cout << "\n"
           "The masks used in\n"
           "\n"
           "   bit_print(): " << bit_print(mask1) << "\n"
           "\n"
           "      unpack(): " << bit_print(mask2 << n0) << "\n"
           "                " << bit_print(mask2 << n1) << "\n"
           "                " << bit_print(mask2 << n2) << "\n"
           "                " << bit_print(mask2 << n3) << "\n"
           "\n"
           "Values and bit prints for\n"
           "\n"
           "    a1 = " << a1 << " = " << bit_print(a1) << "\n"
           "    a2 = " << a2 << " = " << bit_print(a2) << "\n"
           "    a3 = " << a3 << " = " << bit_print(a3) << "\n"
           "    a4 = " << a4 << " = " << bit_print(a4) << "\n"
           "\n"
           "After packing a1-a4 into pkg:\n"
           "\n"
           "   pkg = " << bit_print(pkg) << "\n"
           "\n"
           "After unpacking pkg into b1-b4:\n"
           "\n"
           "    b1 = " << b1 << "\n"
           "    b2 = " << b2 << "\n"
           "    b3 = " << b3 << "\n"
           "    b4 = " << b4 << "\n"
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

//
// Pack 4 characters into an int.
//

int pack(char a, char b, char c, char d)
{
   int   p = a;                             // p will be packed with a, b, c, d

   p = (p << CHAR_BIT) | b;
   p = (p << CHAR_BIT) | c;
   p = (p << CHAR_BIT) | d;
   return p;
}

//
// Unpack a byte from an int.
//

char unpack(int p, int k)                                  // k = 0, 1, 2, or 3
{
   int        n = k * CHAR_BIT;                          // n = 0, 8, 16, or 24
   unsigned   mask = 255;                                     // low-order byte

   assert(0 <= k && k <= 3);
   mask <<= n;
   return ((p & mask) >> n);
}
