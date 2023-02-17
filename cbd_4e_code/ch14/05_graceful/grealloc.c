#include "g_lib.h"

void *grealloc(void *p, size_t sizeof_something)
{
   void   *q;

   if ((q = realloc(p, sizeof_something)) == NULL) {
      fprintf(stderr, "\nERROR:  realloc() failed - bye.\n\n");
      exit(1);
   }
   return q;
}
