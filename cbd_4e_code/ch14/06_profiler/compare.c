#include "cmp_sorts.h"

int compare(const void *vp, const void *vq)
{
   const int   *p;
   const int   *q;
   
   p = (const int *) vp;
   q = (const int *) vq;

   return (*p - *q);
}
