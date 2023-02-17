#include <math.h>
#include <stdio.h>

double   f(double x);

int main(void)
{
   double   x;

   for (x = -0.25; x <= +0.25; x += 0.01)
      printf("f(%+.2f) = %+.15f\n", x, f(x));
   return 0;
}

double f(double x)
{
   return (tan(sin(x)) - sin(tan(x)));
}
