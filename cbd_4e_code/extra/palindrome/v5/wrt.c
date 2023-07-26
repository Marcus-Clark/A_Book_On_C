#include "palindrome.h"

void wrt_help(cchr* pgm_name)
{
   cout << "---\n"
           "Usage:  " << pgm_name << " [-ht] filename\n"
           "\n"
           "Palindromes will be found in the named file.\n"
           "\n"
           "---\n"
           "Options:\n"
           "   -h   help option, print this message\n"
           "   -t   test option, help for the programmer\n"
           "\n";
}
