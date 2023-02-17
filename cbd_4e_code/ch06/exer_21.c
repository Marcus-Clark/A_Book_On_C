/*
// What is the largest double on your system?
*/

#include <stdio.h>
#include <float.h>

int main(void)
{
   double   x = 1.0, y = -1.0, z = 0.0;

   putchar('\n');
   printf("The largest double: %.3e\n", DBL_MAX);
   printf("  Add a little bit: %.3e\n", DBL_MAX + 1.0);
   printf("         Add a lot: %.3e\n", DBL_MAX + DBL_MAX);
   printf("  Division by zero: %.3e  %.3e\n", x / z, y / z);
   putchar('\n');
   return 0;
}
