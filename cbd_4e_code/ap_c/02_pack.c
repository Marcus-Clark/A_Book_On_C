//
// ---
// This program tests the pack() function.
//
// This version of pack() only works on machines with
// 4-byte words, and the output is machine-dependent.
//

#include <iostream.h>
#include <limits.h>

void   bit_print(int a);
int    pack(char a, char b, char c, char d);

int main()
{
   int   abcd = pack('a', 'b', 'c', 'd');

   cout << "\n   abcd = ";
   bit_print(abcd);
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
