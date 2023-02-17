#include "sort.h"

int compare_fractional_part(const void *vp, const void *vq)
{
   const float   *p = vp, *q = vq;
   float         x;

   x = fractional_part(*p) - fractional_part(*q);
   return ((x < 0.0) ? -1 : (x == 0.0) ? 0 : +1);
}

int lexico(const void *vp, const void *vq)
{
   const char   *p = vp, *q = vq;
   return (*p - *q);
}
