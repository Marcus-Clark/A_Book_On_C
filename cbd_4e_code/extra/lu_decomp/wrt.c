#include "lu_decomp.h"

void wrt_help(cchr* pgm_name)
{
   cchr*&   pg = pgm_name;

   cout << "---\n"
           "Usage:  " << pg << " [-f filename]"
                               " [-p precision]"
                               " [-time]"
                               " [-hntv] n\n"
           "\n"
           "The LU decompostion of an n x n matrix A will be computed.\n"
           "\n"
           "Example: " << pg << " 7\n"
           "\n"
           "The coefficients of A will be integer values randomly\n"
           "distributed in the interval [-9, +9], unless the -f\n"
           "option is used.  With this option, the coefficients\n"
           "will be taken from the named file.\n"
           "\n"
           "---\n"
           "Options:\n"
           "   -f     file option, get matrix entries from the named file\n"
           "   -h     help option, print this message\n"
           "   -n     norm check only option, print only the norm check\n"
           "   -p     precision option, set the precision explicitly\n"
           "   -t     test option, help for the programmer\n"
           "   -time  time option, print the running time of the program\n"
           "   -v     verbose option, print more information\n"
           "\n";
}
