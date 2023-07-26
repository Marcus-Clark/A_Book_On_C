#include "bit_print.h"

void prn_info(cchr* pgm_name)
{
   printf("%s\n",
      "---\n"
      "Usage:    pgm [-h] [n1 n2 ...]\n"
      "\n"
      "Example:  pgm 3377\n"
      "\n"
      "Example:  pgm\n"
      "\n"
      "This program bit prints integer values.  The integers can\n"
      "be given on the command line or typed in interactively.\n"
      "\n"
      "---\n"
      "Options:\n"
      "\n"
      "   -h   help option, print this message\n");
}
