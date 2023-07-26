#include "wrt_char.h"

void chk_xterm_window()
{
   cchr*        fct_name = "chk_xterm_window()";

   char         line[maxline];
   char         tfn[maxstring];
   char*        cmnd;
   cchr*        p;
   ifstream     ifs;
   ostrstream   oss;

   // ---
   // The following are global variables:
   //
   //       mnc = minimum number of columns
   //       mnl = minimum number of lines
   //     ncols = number of columns in the current xterm window
   //    nlines = number of lines in the current xterm window
   //
   assert(ncols == -1);
   assert(nlines == -1);
   assert(isatty(1));
   tmpnam(tfn);
   oss << "resize > " << tfn << ends;
   cmnd = oss.str();
   gsystem(cmnd);
   delete [] cmnd;
   ifs.open(tfn);
   assert(ifs);
   while (ifs.getline(line, maxline)) {
      if (strstr(line, "COLUMNS") != NULL) {
         for (p = line + 7; *p != '\0' && !isdigit(*p); ++p)
            ;
         istrstream   iss(p);
         iss >> ncols;
         assert(iss);
      }
      else if (strstr(line, "LINES") != NULL) {
         for (p = line + 5; *p != '\0' && !isdigit(*p); ++p)
            ;
         istrstream   iss(p);
         iss >> nlines;
         assert(iss);
      }
   }
   ifs.close();
   gremove(tfn);
   assert(ncols > 0);
   assert(nlines > 0);
   //
   // mnc = minimum number of columns
   // mnl = minimum number of lines
   //
   if (ncols < mnc || nlines < mnl)
      error_exit_xterm_window_too_small();
   //
   // If the test option is on, write everything on the screen.
   //
   if (o.test_option()) {
      cout << "---\n"
              "TEST OPTION: In " << fct_name << ":\n"
              "\n"
              "      mnc = " << mnc    << "\n"
              "      mnl = " << mnl    << "\n"
              "    ncols = " << ncols  << "\n"
              "   nlines = " << nlines << "\n"
              "\n";
   }
}

cchr* report(int val)
{
   return ((val != 0) ? "1" : "0");
}

cchr* report(off_on val)
{
   return ((val == off) ? "off" : "on");
}

void set_bits(termios& t)
{
   int   bits = ICANON | ISIG | ECHO ;

   t.c_lflag &= ~bits ;    // disable canonical mode, interrupts and echo
   t.c_iflag &= ~IXON ;               // ensure xon and xoff are disabled
   //
   // NOTE:
   //    At this time I do not know how these flags get
   //    used.  The man pages are opaque on these matters
   //    and I do not have answerbook available now.
   //    To understand how this all works, I need
   //    to look elsewhere [in answerbook?].
   //
   // We expect certain members of the structure
   // to have particular values.  We want to be
   // informed if our expectations are wrong.
   // The original code assigned values
   // to be certain that they were
   // correct.
   //
   // The original code follows the assertions.
   //
   // WHOOPS:
   //    It turns out that the first assertion
   //    fails, so we will print the values
   //    when the test option is on.
   //
   if (o.test_option())
      wrt_c_cc_array(t);
   // assert(t.c_cc[VMIN] == 1);
   assert(t.c_cc[VTIME] == 0);
   //
   // The original code just sets the values.
   //
   t.c_cc[VMIN] = 1 ;                            // in case this is not 1
   t.c_cc[VTIME] = 0 ;                           // in case this is not 0
}
