#include <stdio.h>

int main(void)
{
   double   sum = 0.0, x;

   printf("%5s%15s\n", "Value", "Running sum");
   printf("%5s%15s\n", "-----", "-----------");
   for (x = 0.0; x != 9.9; x += 0.1) {            /*test not robust*/
      sum += x;
      printf("%5.1f%15.1f\n", x, sum);
   }
   return 0;
}
