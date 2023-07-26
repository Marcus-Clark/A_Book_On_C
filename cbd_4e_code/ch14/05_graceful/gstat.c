#include "g_lib.h"

void gstat(const char *path, struct stat *statbuf_ptr)
{
   if (stat(path, statbuf_ptr) == -1) {
      perror("TROUBLE: stat()");
      fprintf(stderr, "\nTROUBLE with %s in stat() - bye.\n\n", path);
      exit(1);
   }
}
