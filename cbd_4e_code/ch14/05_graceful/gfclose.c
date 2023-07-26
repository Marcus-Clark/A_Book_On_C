#include "g_lib.h"

void gfclose(FILE *fp)
{
   if (fclose(fp) == -1) {
      fprintf(stderr, "\nERROR:  fclose() failed - bye.\n\n");
      exit(1);
   }
}
