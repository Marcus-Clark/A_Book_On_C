#include "g_lib.h"

FILE *gpopen(const char *cmnd, const char *mode)
{
   FILE   *fp;

   if ((fp = popen(cmnd, mode)) == NULL) {
      fprintf(stderr, "\nCannot open \"%s\" - bye.\n\n", cmnd);
      exit(1);
   }
   return (fp);
}
