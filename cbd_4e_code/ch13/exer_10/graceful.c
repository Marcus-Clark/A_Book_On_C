/*
// A graceful version of fopen().
*/

#include "careful.h"

FILE *gfopen(cchr *filename, cchr *mode)
{
   FILE   *fp;

   if ((fp = fopen(filename, mode)) == NULL) {
      fprintf(stderr, "\nCannot open %s - bye.\n\n", filename);
      exit(1);
   }
   return fp;
}
