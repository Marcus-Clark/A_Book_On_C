/*
// A graceful version of calloc().
*/

#include "try_me.h"

void *gcalloc(size_t n, size_t sizeof_something)
{
   void   *p;

   if ((p = calloc(n, sizeof_something)) == NULL) {
      printf("\nERROR: calloc() failed - bye!\n\n");
      exit(1);
   }
   return p;
}
