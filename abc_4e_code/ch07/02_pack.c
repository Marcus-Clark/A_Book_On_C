/* Pack 4 characters into an int. */

#include <limits.h>

int pack(char a, char b, char c, char d)
{
   int   p = a;               /* p will be packed with a, b, c, d */

   p = (p << CHAR_BIT) | b;
   p = (p << CHAR_BIT) | c;
   p = (p << CHAR_BIT) | d;
   return p;
}
