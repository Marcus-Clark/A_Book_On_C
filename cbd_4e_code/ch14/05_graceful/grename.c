#include "g_lib.h"

void grename(const char *from, const char *to)
{
   if (rename(from, to) != 0) {
      fprintf(stderr, "\nERROR:  rename() failed - bye.\n\n");
      exit(1);
   }
}
