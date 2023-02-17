#include <stdio.h>

int main(void)
{
   int   i;

   struct test {
      int   a : 3, b : 4;
   } x = {0};

   for (i = 0; i < 33; ++i)
      printf("x.a = %2d   x.b = %2d\n", x.a++, x.b++);
   return 0;
}
