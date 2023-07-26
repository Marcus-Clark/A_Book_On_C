#include "mk_cols.h"

void wrt_fw(int* fw, int n)
{
   int   j;

   assert(n > 0);
   for (j = 1; j <= n; ++j)
      cout << "   fw[" << j << "] = " << fw[j] << "\n";
}

void wrt_help(cchr* pgm_name)
{
   cchr*&   pg = pgm_name;

   cout << "---\n"
           "Usage:    " << pg << " { N | -N } [-h]"
                      " [-i n] [-s n] [-u] [-w n] [filename]\n"
           "\n"
           "Examples: " << pg << "  3       filename\n"
           "          " << pg << "  3       filename > output\n"
           "          " << pg << " -7     < filename > output\n"
           "          " << pg << " -7 -i2 < filename > output\n"
           "\n"
           "Example with a pipe:\n"
           "\n"
           "          ... | " << pg << " -7 > output\n"
           "\n"
           "Words from the named file, or the standard input file\n"
           "if there is no filename, are printed in N columns.\n"
           "\n"
           "---\n"
           "Options:\n"
           "   -N     number of columns to be printed, N must be positive\n"
           "   -h     help option, print this message\n"
           "   -i n   indent option, indent each line n spaces\n"
           "   -s n   space option, set the min # of blank spaces between cols\n"
           "   -t     test option, help for the programmer\n"
           "   -u     uppercase option, change lowercase letters to uppercase\n"
           "   -w n   width option, set the screen width\n"
           "\n";
}
