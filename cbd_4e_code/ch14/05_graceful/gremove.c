#include "g_lib.h"

void gremove(const char *fname)
{
   if (remove(fname) == -1) {
      fprintf(stderr, "\nERROR:  remove() failed - bye.\n\n");
      exit(1);
   }
}
