#include <stdio.h>

void   bit_print(int a);

int main(void)
{
   int   i, power = 1;

   for (i = 0; i < 32; ++i) {
      printf("%2d:  ", i);
      bit_print(power);
      printf("   ");
      bit_print(power -  1);
      putchar('\n');
      power *= 2;
   }
   return 0;
}
