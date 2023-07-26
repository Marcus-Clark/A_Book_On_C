#include "g_lib.h"

int gchmod(const char *path, mode_t mode)
{
   int          val;
   extern int   errno, sys_nerr;

   if ((val = chmod(path, mode)) == -1) {
      if (errno > 0 && errno < sys_nerr)
         perror("ERROR: gchmod()");
      exit(1);
   }
   return val;
}
