/*
// This program has the following output:
//
//    AAA  B CC DDD EEEE FFFFF GGGGGG HHHHHHH IIIIIIII JJJJJJJJJ
//
// Between A and B there are two spaces characters, but between
// other letters only one space character.  Why?
*/

#include <ctype.h>
#include <stdio.h>

void   repeat(char c, int n);

int main()
{
   int          i;
   const char   alert = '\a', c = 'A';

   repeat('B' - 1, 3);
   putchar(' ');
   for (i = 0; i < 10; ++i) {
      repeat(c + i, i);
      putchar(' ');
   }
   repeat(alert, 100);
   putchar('\n');
   return 0;
}

void repeat(char c, int n)
{
   int   i;

   for (i = 0; i < n; ++i)
      putchar(c);
}
