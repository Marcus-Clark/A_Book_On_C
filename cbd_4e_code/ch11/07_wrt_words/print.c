#include "wrt_bkwds.h"

void prn_info(cchr* pgm_name)
{
   cout << "---\n"
           "Usage:  " << pgm_name << " [-h] filename\n"
           "\n"
           "The last word in the input file is written to stdout,\n"
           "then the next to the last word, and so forth.  The\n"
           "contents of the input file does not get changed.\n"
           "\n"
           "---\n"
           "Options:\n"
           "   -h   help option, print this message\n"
           "\n";
}
