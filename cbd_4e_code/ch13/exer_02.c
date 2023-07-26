#include <stdio.h>

int main(void)
{
   int   n1, n2;

   printf("try %n me %n \n", &n1, &n2);
   printf("n1 = %d  n2 = %d\n", n1, n2);
   return 0;
}
