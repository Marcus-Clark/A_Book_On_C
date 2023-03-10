#include "g_lib.h"

FILE *gfopen(const char *filename, const char *mode)
{
   FILE   *fp;

   if ((fp = fopen(filename, mode)) == NULL) {
      fprintf(stderr, "\nCannot open %s - bye.\n\n", filename);
      exit(1);
   }
   return (fp);
}
