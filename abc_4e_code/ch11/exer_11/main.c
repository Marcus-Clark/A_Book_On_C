#include "wrt_rand.h"

int main(void)
{
   char   fname[MAXSTRING];                         /* output filename */
   int    n;                         /* no. of random numbers to write */
   FILE   *ofp;                                     /* outfile pointer */

   get_info(fname, &n);
   ofp = cfopen(fname, "w");
   wrt_rand(ofp, n);
   fclose(ofp);
   return 0;
}
