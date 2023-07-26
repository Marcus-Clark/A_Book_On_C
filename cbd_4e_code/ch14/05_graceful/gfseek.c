#include "g_lib.h"

void gfseek(FILE *fp, long offset, int place)
{
   if (fseek(fp, offset, place) == -1) {
      fprintf(stderr, "\nCall to fseek() failed - bye.\n\n");
      exit(1);
   }
}
