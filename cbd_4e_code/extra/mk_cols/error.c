#include "mk_cols.h"

void error_exit_cannot_open(cchr* fname)
{
   cout << "---\n"
           "Cannot open " << fname << " - bye!\n"
           "\n";
   exit(1);
}

void error_exit_indent_not_found()
{
   cout << "---\n"
           "ERROR: Indent value after -i flag not found - bye!\n"
           "\n";
   exit(1);
}

void error_exit_indent_not_found(cchr* s)
{
   cout << "---\n"
           "ERROR:\n"
           "\n"
           "   Indent value after -i flag not found.\n"
           "   Here is the string that was found:\n"
           "\n"
           "      s = " << s << "\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void error_exit_ncols_must_be_positive(int ncols, cchr* s)
{
   cout << "---\n"
           "ERROR:\n"
           "\n"
           "   The number of columns must be positive.  Here is the\n"
           "   erroneous specification and the value found:\n"
           "\n"
           "      specification: " << s     << "\n"
           "              value: " << ncols << "\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void error_exit_ncols_not_found(cchr* s)
{
   cout << "---\n"
           "ERROR:\n"
           "\n"
           "   Number of columns not found on the command line.\n"
           "   Here is the erroneous specification:\n"
           "\n"
           "      " << s << "\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void error_exit_nonnegative_integer_required(int val)
{
   cout << "---\n"
           "ERROR:\n"
           "\n"
           "   A nonnegative integer is required after the -s flag.\n"
           "   Here is the value found:\n"
           "\n"
           "      value: " << val << "\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void error_exit_positive_integer_required(int val)
{
   cout << "---\n"
           "ERROR:\n"
           "\n"
           "   A positive integer is required after the -w flag.\n"
           "   Here is the value found:\n"
           "\n"
           "      value: " << val << "\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void error_exit_space_not_found()
{
   cout << "---\n"
           "ERROR: Space after -s flag not found - bye!\n"
           "\n";
   exit(1);
}

void error_exit_space_not_found(cchr* s)
{
   cout << "---\n"
           "ERROR:\n"
           "\n"
           "   Space after -s flag not found.\n"
           "   Here is the string that was found:\n"
           "\n"
           "      s = " << s << "\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void error_exit_too_many_cmnd_line_args()
{
   cout << "---\n"
           "ERROR: Too many filenames on the command line - bye!\n"
           "\n";
   exit(1);
}

void error_exit_width_not_found()
{
   cout << "---\n"
           "ERROR: Width after -w flag not found - bye!\n"
           "\n";
   exit(1);
}

void error_exit_width_not_found(cchr* s)
{
   cout << "---\n"
           "ERROR:\n"
           "\n"
           "   Width after -w flag not found.\n"
           "   Here is the string that was found:\n"
           "\n"
           "      s = " << s << "\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void whoops_exit_ncols_not_specified()
{
   cout << "---\n"
           "WHOOPS: Number of columns not specified -- bye!\n"
           "\n";
   exit(1);
}

void whoops_exit_too_many_ncols_specified()
{
   cout << "---\n"
           "WHOOPS:\n"
           "\n"
           "   Number of columns specified too many times\n"
           "   on the command line.\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}
