#include <stdio.h>

#define   LUCKY_NUMBER   777

int main(void)
{
   int   *p = LUCKY_NUMBER;

   printf("Is this my lucky number?  %d\n", *p);
   return 0;
}
