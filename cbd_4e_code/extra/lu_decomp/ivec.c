#include "lu_decomp.h"

ivec::ivec(int n)
{
   get_space(1, n);
}

ivec::ivec(int m, int n)
{
   get_space(m, n);
}

void ivec::get_space(int n)
{
   get_space(1, n);
}

void ivec::get_space(int m, int n)
{
   assert(m <= n);
   bgn = m;
   sz = n - m + 1;
   el = (new int [sz]) - m;                              // index from m, not 0
}

void ivec::release_space()
{
   assert(   el == NULL && sz == 0
          || el != NULL && sz >= 1);
   if (el != NULL) {
      delete [] (el + bgn);
      el = NULL;
      sz = 0;
   }
}
