/*
// Capitalize lowercase letters and double space.
//
// Typical usage:
//
//    caps < infile
//
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
   int   c;

   while ((c = getchar()) != EOF)
      if (islower(c))
       putchar(toupper(c));
      else if (c == '\n') {
         putchar('\n');
         putchar('\n');
      }
      else
         putchar(c);
   return 0;
}
