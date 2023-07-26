#include <stdio.h>

int main(void)
{
   int   a[] = {0, 2, 4, 6, 8},
         *p = a + 3;

   printf("%s%d%s\n%s%d%s\n",
      "a[?]   = ", *p,     "?",
      "a[?+1] = ", *p + 1, "?");
   return 0;
}

