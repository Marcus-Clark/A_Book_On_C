#include <stdio.h>
#include <stdlib.h>

#define   FOREVER   1
#define   STOP      17

int main(void)
{
   void   f(void);

   while (FOREVER)
      f();
   return 0;
}

void f(void)
{
   static int   cnt = 0;

   printf("cnt = %d\n", ++cnt);
   if (cnt == STOP)
      exit(0);
}
