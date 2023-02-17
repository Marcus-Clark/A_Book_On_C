#include "palindrome.h"

void error_exit_cannot_open(cchr* fname)
{
   cout << "---\n"
           "Cannot open " << fname << " - bye!\n"
           "\n";
   exit(1);
}

void error_exit_too_many_filenames()
{
   cout << "---\n"
           "ERROR: Too many filenames on the command line:\n"
           "\n";
   wrt_help(o.local_pgm_name());
   exit(1);
}
