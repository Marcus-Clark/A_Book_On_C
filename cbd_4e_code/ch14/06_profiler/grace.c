#include "g_lib.h"

void *gcalloc(size_t n, size_t sizeof_something)
{
   void   *p;

   if ((p = calloc(n, sizeof_something)) == NULL) {
      fprintf(stderr, "\n%s\n%s%d%s%d\n\n",
         "ERROR: calloc(n, sizeof_something) has failed",
         "with n = ", n, " and sizeof_something = ", sizeof_something);
      exit(1);
   }
   return p;
}
