#include <stdio.h>
#include <stddef.h>

int main(void)
{
   int         a, b, *p = &a, *q = &b;
   ptrdiff_t   diff = p  q;
   printf("diff = %d\n", diff);
   return 0;
}
