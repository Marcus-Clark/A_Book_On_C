/*
// The value of a a variable and the address
// of a variable are conceptually different.
*/

#include <stdio.h>

int main(void)
{
   int   i = 777, *p = &i;

   printf("  Value of i: %d\n", *p);
   printf("Address of i: %u or %p\n", p, p);
   return 0;
}
