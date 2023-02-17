#include <stdio.h>

void swap(int *p, int *q);

int main(void)
{
   int   a = 3, b = 7;

   printf("%d  %d\n", a, b);     /* 3  7 is printed */
   swap(&a, &b);
   printf("%d  %d\n", a, b);     /* 7  3 is printed */
   return 0;
}

void swap(int *p, int *q)
{
   int   tmp;

   tmp = *p;
   *p = *q;
   *q = tmp;
}
