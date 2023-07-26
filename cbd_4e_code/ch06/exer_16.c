/*
// What gets printed?  Write down your
// answer before you execute the program.
*/

#include <stdio.h>

int main(void)
{
   char   a = 1, b = 2, c = 3;

   printf("sizeof(c)           = %d\n", sizeof(c));
   printf("sizeof('a')         = %d\n", sizeof('a'));
   printf("sizeof(c = 'a')     = %d\n", sizeof(c = 'a'));
   printf("sizeof(a + b + 7.7) = %d\n", sizeof(a + b + 7.7));
   return 0;
}
