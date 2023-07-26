#include "c_align.h"

void error_exit_cannot_access(cchr* fname)
{
   cout << "\nCannot access " << fname << " - bye!\n\n";
   exit(1);
}

void error_exit_cannot_get_here(cchr* place)
{
   cout << "---\n"
           "PROGRAMMER ERROR:\n"
           "\n"
           "   Cannot get to " << place << "\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void error_exit_cannot_open(cchr* fname)
{
   cout << "---\n"
           "Cannot open " << fname << " - bye!\n\n";
   exit(1);
}

void error_exit_closing_char_not_found(cchr* fn, cchr ch, int ct, cchr* li)
{
   cchr*&   fname = fn;
   int&     cnt = ct;
   cchr*&   line = li;

   cout << "---\n"
           "ERROR:\n"
           "\n"
           "   Closing character not found:\n"
           "\n"
           "      filename: " << fname <<"\n"
           "     character: " << ch    <<"\n"
           "   line number: " << cnt   <<"\n"
           "          line: " << line  <<"\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void error_exit_comment_not_closed(cchr* fname, int cnt, cchr* line)
{
   cout << "---\n"
           "ERROR:\n"
           "\n"
           "   Comment not closed:\n"
           "\n"
           "      filename: " << fname <<"\n"
           "   line number: " << cnt   <<"\n"
           "          line: " << line  <<"\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void error_exit_filename_ext_not_found(cchr* fname)
{
   fname_ext   e;

   cout << "---\n"
           "ERROR:\n"
           "\n"
           "   Filename extension not found:\n"
           "\n"
           "      filename: " << fname <<"\n"
           "\n"
           "   Here are the acceptable filename extensions:\n"
           "\n"
           "      " << e << "\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void error_exit_mixed_comment(cchr* fname, int cnt, cchr* line, cchr* comment)
{
   cout << "---\n"
           "ERROR: Mixed comment found:\n"
           "\n"
           "         fname: " << fname   <<"\n"
           "   line number: " << cnt     <<"\n"
           "          line: " << line    <<"\n"
           "       comment: " << comment <<"\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void error_exit_not_a_comment(cchr* fname, int cnt, cchr* line, cchr* comment)
{
   cout << "---\n"
           "ERROR: Not a comment:\n"
           "\n"
           "         fname: " << fname   <<"\n"
           "   line number: " << cnt     <<"\n"
           "          line: " << line    <<"\n"
           "       comment: " << comment <<"\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void error_exit_positive_integer_required(int re)
{
   assert(o.right_edge_option() == on);
   cout << "---\n"
           "ERROR:\n"
           "\n"
           "   Positive integer required after -r option.\n"
           "   Here is the value found for the right edge:\n"
           "\n"
           "      " << re << "\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void error_exit_right_edge_not_found()
{
   assert(o.right_edge_option() == on);
   cout << "---\n"
           "ERROR:\n"
           "\n"
           "   Right edge after -r option not found.\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void error_exit_right_edge_not_found(cchr* s)
{
   assert(o.right_edge_option() == on);
   cout << "---\n"
           "ERROR:\n"
           "\n"
           "   Right edge after -r option not found.\n"
           "   Here is what follows the -r option:\n"
           "\n"
           "      " << s << "\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void error_exit_style_not_found()
{
   assert(o.right_edge_option() == on);
   cout << "---\n"
           "ERROR:\n"
           "\n"
           "   Style after -s option not found.\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void error_exit_style_not_found(cchr* s)
{
   assert(o.right_edge_option() == on);
   cout << "---\n"
           "ERROR:\n"
           "\n"
           "   Style after -s option not found.\n"
           "   Here is what follows the -s option:\n"
           "\n"
           "      " << s << "\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

void error_exit_wrong_filename_ext(cchr* fname)
{
   fname_ext   e;

   cout << "---\n"
           "ERROR: Wrong filename extension:\n"
           "\n"
           "   filename = " << fname << "\n"
           "\n"
           "   Here are the allowable filename extensions:\n"
           "\n"
           "      " << e << "\n"
           "\n"
           "   Use the -f option to override the limitation on filename extensions.\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}
