#include <stdio.h>

typedef   float   DOLLARS;

int main(void)
{
   DOLLARS   amount = 100.00,
             interest = 0.07 * amount;
   {                                     /*  new block  */
      float   DOLLARS;
      DOLLARS = amount + interest;
      printf("DOLLARS = %.2f\n", DOLLARS);
   }
   return 0;
}
