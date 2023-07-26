#include "wrt_char.h"

void error_exit_cannot_get_here(cchr* fct_name)
{
   cout << "---\n"
           "PROGRAMMER ERROR:\n"
           "\n"
           "   ---\n"
           "   In " << fct_name << ":\n"
           "\n"
           "   Cannot get to here.\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void error_exit_xterm_window_too_small()
{
   //
   //    mnc = minimum number of columns
   //    mnl = minimum number of lines
   //  ncols = number of columns in the current xterm window
   // nlines = number of lines in the current xterm window
   //
   assert(ncols < mnc || nlines < mnl);
   cout << "---\n"
           "ERROR: Xterm window too small:\n"
           "\n"
           "   number of columns = " << ncols  << "\n"
           "     number of lines = " << nlines << "\n"
           "\n"
           "The window must contain at least " << mnc << " columns and " << mnl << " lines.\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}
