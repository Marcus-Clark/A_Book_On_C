#include "g_lib.h"

void *gmalloc(size_t sizeof_something)
{
   void   *p;

   if ((p = malloc(sizeof_something)) == NULL) {
      fprintf(stderr, "\nERROR:  malloc() failed - bye.\n\n");
      exit(1);
   }
   return p;
}
