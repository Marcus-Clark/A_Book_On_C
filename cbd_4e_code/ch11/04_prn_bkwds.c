/* Write a line backwards. */

#include <stdio.h>

void   prn_it(void);

int main(void)
{
   printf("\nInput a line:  ");
   prn_it();
   printf("\n\n");
   return 0;
}

void prn_it(void)
{
   char   c;

   if ((c = getchar()) != '\n')
      prn_it();
   putchar(c);
}
