#include <stdio.h>

void   change_it(int []);

int main(void)
{
   int    a[5], *p = a;

   printf("p has the value %u\n", (int) p);
   change_it(a);
   p = a;
   printf("p has the value %u\n", (int) p);
   return 0;
}

void change_it(int a[])
{
   int   i = 777, *q = &i;

   a = q;     /* a is assigned a different value */
}
