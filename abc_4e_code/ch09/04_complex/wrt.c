#include "complex.h"

void wrt(char *s, complex z)
{
   printf("   %5s = %+.3f%+.3f*i\n", s, z.re, z.im);
}
