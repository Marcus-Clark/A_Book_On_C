#include <stdio.h>

int main(void)
{
   int   a = 0, b = 0, x;

   x = 0 && (a = b = 777);
   printf("%d %d %d\n", a, b, x);
   x = 777 || (a = ++b);
   printf("%d %d %d\n", a, b, x);
   return 0;
}
