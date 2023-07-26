#include <stdio.h>

int main(void)
{
   int   i = 7, *p;

   p = &i;
   printf("%s%d\n%s%p\n",
      "   Value of i: ", *p,
      "Location of i: ",  p);
   return 0;
}
