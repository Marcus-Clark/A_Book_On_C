/*
// A careful version of fopen().
*/

#include "wrt_rand.h"

FILE *cfopen(char *fname, char *mode)
{
   char   reply[2];
   FILE   *fp;

   if (strcmp(mode, "w") == 0 && access(fname, F_OK) == 0) {
      printf("\nFile exists.  Overwrite it?  ");
      scanf("%1s", reply);
      if (*reply != 'y' && *reply != 'Y') {
         printf("\nBye!\n\n");
         exit(1);
      }
      putchar('\n');
   }
   fp = gfopen(fname, mode);
   return fp;
}
