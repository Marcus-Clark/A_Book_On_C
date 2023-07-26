/*
// It helps if you pipe this program through more.
*/

#include <stdio.h>

int main(void)
{
   for (putchar('1'); putchar('2'); putchar('3')) {
      putchar('4');
      continue;
      putchar('5');
   }
   return 0;
}
