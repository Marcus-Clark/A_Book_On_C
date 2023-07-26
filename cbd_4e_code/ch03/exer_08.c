#include <stdio.h>
 
#define   LIMIT   23

int main(void)
{
   int   i = 0;
   int   j;

   while (++i < LIMIT) do {     /* syntax error */
      j = 2 * i + 3;
      printf("j = %d\n", j);
   }
   return 0;
}
