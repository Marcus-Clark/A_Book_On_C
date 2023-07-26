/*
// A careful version of fopen().
*/

#include "careful.h"

FILE *cfopen(cchr *filename, cchr *mode)
{
   char   reply[2];
   FILE   *fp;

   if (strcmp(mode, "w") == 0
      && (fp = fopen(filename, "r")) != NULL) {
       fclose(fp);
       printf("\nFile exists.  Overwrite it?  ");
       scanf("%1s", reply);
       if (*reply != 'y' && *reply != 'Y') {
          printf("\nBye!\n\n");
          exit(1);
       }
   }
   fp = gfopen(filename, mode);
   return fp;
}
