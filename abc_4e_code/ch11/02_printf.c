#include <stdio.h>

int main(void)
{
   int      i = 123;
   double   x = 0.123456789;

   printf("[%d]\n[%05d]\n[%7o]\n[%-9x]\n[%-#9x]\n[%10.5f]\n[%-12.5e]\n",
      i, i, i, i, i, x, x);
   return 0;
}
