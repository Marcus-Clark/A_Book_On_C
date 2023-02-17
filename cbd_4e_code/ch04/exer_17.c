#include <stdio.h>

void   f(void);
void   g(void);

int main(void)
{
   static int   cnt = 0;

   printf("Hello from main()\n");
   if (++cnt <= 2)
      f();
   return 0;
}

void f(void)
{
   printf("Hello from f()\n");
   g();
}

void g(void)
{
   printf("Hello from g()\n");
   main();
}
