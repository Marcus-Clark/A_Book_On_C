#include "bubble.h"

void prn_info(cchr* pgm_name)
{
   cout << "---\n"
           "Usage:  " << pgm_name << " [-h] filename\n"
           "\n"
           "This program reads lines in the named file, bubble sorts\n"
           "some of the words in each line, and writes the lines to\n"
           "standard out.  The input file does not get changed.\n"
           "\n"
           "---\n"
           "Options:\n"
           "   -h   help option, print this message\n"
           "\n";
}
