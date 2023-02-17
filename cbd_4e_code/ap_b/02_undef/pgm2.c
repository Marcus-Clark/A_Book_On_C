/*
// This program should work fine.
*/

#include <stdio.h>

#undef sun

int main(void)
{
   int   earth = 1, moon = 2, sun = 3;

   printf("sum = %d\n", earth + moon + sun);
   return 0;
}
