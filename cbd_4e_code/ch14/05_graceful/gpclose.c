#include "g_lib.h"

void gpclose(FILE *fp)
{
   if (pclose(fp) == -1) {
      fprintf(stderr, "\nWARNING:  pclose() failed - pipe already empty?\n\n");
   }
}
