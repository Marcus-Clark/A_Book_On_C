#include <math.h>       /* for fabs() */
#include <stdio.h>
#include <stdlib.h>     /* for abs() */

int main(void)
{
   double   x = -2.357;

   printf(" abs(x) = %e\n", abs(x));     /* wrong! */
   printf("fabs(x) = %e\n", fabs(x));
   return 0;
}
