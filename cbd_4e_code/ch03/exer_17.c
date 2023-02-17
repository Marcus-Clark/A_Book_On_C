#include <stdio.h>

int main(void)
{
   int   i, sum = 0;

   for (i = 1; ++i; i <= 5)
      printf("i = %d   sum = %d\n", i, sum += i);
   return 0;
}
