#include "careful.h"

int main(void)
{
   char   ofn[MAXSTRING];                                    /* outfile name */
   int    n;
   FILE   *ofp;

   srand(time(NULL));                    /* seed the random number generator */
   get_info(ofn, &n);
   ofp = cfopen(ofn, "w");
   prn_rand(ofp, n);
   return 0;
}
