/*
// This program is system-dependent, which means
// that on different systems the program may not
// behave the same.
//
// If you have access to a C system on both a
// UNIX machine and an MS-DOS machine, try this
// program on each system to see if it behaves
// differently.
*/

#include <stdio.h>

int main(void)
{
   printf("%d\n", f(2));         /* 7 is printed */
   printf("%d\n", f(2.0));       /* 1 is printed */
   return 0;
}

int f(int n)
{
   return (3 * n + 1);
}
