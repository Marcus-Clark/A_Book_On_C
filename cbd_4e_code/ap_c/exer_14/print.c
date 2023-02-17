#include "try_me.h"

void prn_info(cchr* pgm_name)
{
   cout << "\n"
           "---\n"
           "Usage:    " << pgm_name << " [-h] [n]\n"
           "\n"
           "Example:  " << pgm_name << " 77\n"
           "\n"
           "Example:  " << pgm_name << "\n"
           "\n"
           "Some integers will be bit printed;\n"
           "see exercise 14 on page 640.\n"
           "\n"
           "---\n"
           "Options:\n"
           "   -h   help option, print this message\n"
           "\n";
}
