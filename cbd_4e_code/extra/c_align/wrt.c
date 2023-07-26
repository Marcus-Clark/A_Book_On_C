#include "c_align.h"

void wrt_help(cchr* pgm_name)
{
   cchr*&      pg  = pgm_name;
   cint&       dre = default_right_edge;
   fname_ext   e;

   cout << "---\n"
           "Usage:    " << pg << " [-fht] [-r n] [-s c | -s c++] file1 file2 ...\n"
           "\n"
           "Examples: " << pg << " -r 57 main.c\n"
           "          " << pg << " -s c++ *.[hc]\n"
           "          " << pg << " -s c fct.c\n"
           "\n"
           "The named files will be overwritten with\n"
           "short comments aligned on the right.\n"
           "\n"
           "By default, the right edge is set to " << dre << ".\n"
           "\n"
           "Unless the force option is on, here are\n"
           "the acceptable filename extensions:\n"
           "\n"
           "   .c .cc .cp .cpp .cxx .h .hh .hxx .C .CC .CP .CPP .CXX .H .HH .HXX\n"
           "\n"
           "---\n"
           "Options:\n"
           "   -f      force option, align comments on the right for\n"
           "              any file, regardless of filename extensions\n"
           "   -h      help option, print this message\n"
           "   -r n    right edge option, set the right edge of all\n"
           "              adjustable comments to col n\n"
           "   -s c    style option, comments on the right are\n"
           "              written in the C style\n"
           "   -s c++  style option, comments on the right are\n"
           "              written in the C++ style\n"
           "   -t      test option, help for the programmer,\n"
           "              no files get overwritten\n"
           "\n";
}
