#include <stdio.h>

int main(void)
{
   char     *pc = NULL;
   int      *pi = NULL;
   double   *pd = NULL;

   printf("%d  %d  %d\n%d  %d  %d\n",
      (int)(pc + 1), (int)(pi + 1), (int)(pd + 1),
      (int)(pc + 3), (int)(pi + 5), (int)(pd + 7));
   return 0;
}
