/*
// The call to swap() has the side effect
// of altering the stored values of
// some external variables.
//
// To do this is considered bad programming style.
*/

#include <stdio.h>

int    a = 3, b = 7;             /* global variables */

void   swap(void);

int main(void)
{
   printf("%d  %d\n", a, b);     /* 3  7 is printed */
   swap();
   printf("%d  %d\n", a, b);     /* 7  3 is printed */
   return 0;
}

void swap(void)         /* very bad programming style */
{
   extern int   a, b;
   int          tmp;

   tmp = a;
   a = b;
   b = tmp;
}
