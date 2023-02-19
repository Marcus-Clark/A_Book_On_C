#include "find_roots.h"

dbl f1(dbl x)
{
   return (x*x*x - x*x + 2.0*x - 2.0);
}

dbl f2(dbl x)
{
   return (sin(x) - 0.7*x*x*x + 3.0);
}

dbl f3(dbl x)
{
   return (exp(0.13*x) - x*x*x);
}
