#include <stdio.h>
/* Ex 11 fixed */
int main(void)
{
   int   a[] = {0, 2, 4, 6, 8},
         *p = a + 2;

   printf("%s%d%s\n%s%d%s\n",
      "a[?]   = ", *p,     "?",
      "a[?+1] = ", *(p + 1), "?"); 
      
      /* *(p + i)  is equivalent to p[i] p254
       * so it prints the next element */
       
   return 0;
}

