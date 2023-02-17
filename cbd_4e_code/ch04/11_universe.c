#include <stdio.h>

int main(void)
{
   int   cnt = 0;

   if (++cnt < 77) {
      printf("   The universe is ever expaning!   ");
      main();
   }
   return 0;
}
