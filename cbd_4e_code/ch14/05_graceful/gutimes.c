#include "g_lib.h"

void gutimes(char *path, struct timeval *tvp)
{
   int   utimes();

   if (utimes(path, tvp) == -1) {
      perror("TROUBLE: utimes()");
      fprintf(stderr, "\nTROUBLE with %s in utimes() - bye.\n\n", path);
      exit(1);
   }
}
