#include <stdio.h>

int main(void)
{
   int   i = 2, j = 4, k = 6;
   int   *p = &i, *q = &j, *r = &k;

   printf("%d\n",  *  p  /  *  q  /  *  r);
   printf("%d\n",  ++  *  p  /  --  *  q  /  ++  *  r);
   return 0;
}
