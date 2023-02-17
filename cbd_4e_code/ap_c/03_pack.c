//
// ---
// This program tests the pack() function.
//
// This version of pack() works on machines with either
// 2- or 4-byte words.  The output is machine-dependent.
//

#include <iostream.h>
#include <limits.h>

void   bit_print(int a);
int    pack(char a, char b);

int main()
{
   int   ab = pack('a', 'b');

   cout << "\n   ab = ";
   bit_print(ab);
   cout << "\n\n";
}

//
// Bit print an int expression.
//

void bit_print(int a)
{
   int   i;
   int   n = sizeof(int) * CHAR_BIT;                             // in limits.h
   int   mask = 1 << (n - 1);                                 // mask = 100...0

   for (i = 1; i <= n; ++i) {
      cout << (((a & mask) == 0) ? '0' : '1');
      a <<= 1;
      if (i % CHAR_BIT == 0 && i < n)
         cout << ' ';
   }
}

//
// Pack 2 characters into an int.
//

int pack(char a, char b)
{
   int   p = a;                                // p will be packed with a and b

   p = (p << CHAR_BIT) | b;
   return p;
}
