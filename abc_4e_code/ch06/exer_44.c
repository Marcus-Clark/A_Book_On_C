#include <stdio.h>

void   f(void);
void   g(void);
void   h(void);

int main(void)
{
   (*f)();
   return 0;
}

void f(void)
{
   printf("Hello from f().\n");
   (((*g)))();
}

void g(void)
{
   printf("Hello from g().\n");
   (*(*(*h)))();
}

void h(void)
{
   printf("Hello from h().\n");
}
