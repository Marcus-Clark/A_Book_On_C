#include <iostream.h>

void   f(void);
void   g(void);

int main(void)
{
   static int   cnt = 0;

   cout << "Hello from main()\n";
   if (++cnt <= 2)
      f();
}

void f(void)
{
   cout << "Hello from f()\n";
   g();
}

void g(void)
{
   cout << "Hello from g()\n";
   main();
}
