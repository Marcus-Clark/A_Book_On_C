#include <stdio.h>
#include <math.h>

#define   PI   3.14159

typedef   double   dbl;             /* create an abbreviation */
typedef   dbl      (*PFDD)(dbl);    /* ptr to fct of dbl returning dbl */

int main(void)
{
   PFDD   f = sin, g = cos;

   printf("f(%f) = %f\n", PI, f(PI));
   printf("g(%f) = %f\n", PI, g(PI));
   return 0;
}
