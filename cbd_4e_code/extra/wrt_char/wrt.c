#include "wrt_char.h"

void wrt_all_names()
{
   // ---
   // cchr* name[] = {
   //    "nul",  "soh",  "stx",  "etx",  "eot",  "enq",  "ack",  "bel",
   //    "bs",   "ht",   "nl",   "vt",   "np",   "cr",   "so",   "si",
   //    "dle",  "dc1",  "dc2",  "dc3",  "dc4",  "nak",  "syn",  "etb",
   //    "can",  "em",   "sub",  "esc",  "fs",   "gs",   "rs",   "us",
   //    "sp"
   // };
   //

   cchr* dictionary[] = {
      "null", "?", "?", "?", "end of transmission", "enquire?", "acknowledge?",
      "bell", "backspace", "horizontal tab", "newline", "vertical tab", "?",
      "carriage return", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?",
      "?", "?", "?", "escape", "?", "?", "?", "?", "space"
   };

   int   i;
   int   nn = 33;                                      // number of names

   //
   // Because const char* [] is an incomplete
   // type, the following does not work:
   //
   //    assert(sizeof(name) == sizeof(dictionary));
   //
   cout << "---\n"
           "WRITE ALL NAMES OPTION:\n"
           "\n";
   for (i = 0; i < nn; ++i)
      cout << setw(6) << name[i] << " = " << dictionary[i] << "\n";
   cout << "\n";
}

void wrt_c_cc_array(const termios& t)
{
   cchr*         fct_name = "wrt_c_cc_array()";

   char          answer[maxstring];
   char          line[maxline];
   char**        p;
   int           i;
   int           k;
   int           n;
   field_width   fw1;
   field_width   fw2(2);
   ostrstream*   oss;


   assert(o.test_option());
   cout << "---\n"
           "TEST OPTION: In " << fct_name << ":\n"
           "\n"
           "Here are some elements from the original code\n"
           "that were used to access the c_cc array in\n"
           "the termios structure:\n"
           "\n"
           "   NCCS  = " << NCCS  << "\n"
           "   VMIN  = " << VMIN  << "\n"
           "   VTIME = " << VTIME << "\n"
           "\n"
           "Before setting any bits, here are all\n"
           "the elements of the array:\n"
           "\n";
   //
   // We want two columns, with the numbering
   // going down the columns, not across.
   //
   // If NCCS has value 19, then n will have
   // value 20 and k will have value 10,
   // and the numbering down the first
   // column will be from 0 to 9.
   //
   n = (NCCS % 2 == 0) ? NCCS : NCCS + 1;
   k = n / 2;
   assert(n == 2 * k);
   //
   // Clear 10 on the first column.
   //
   // Note:
   //   This algorith needs to be sharpened
   //   if NCCS is something other than 19.
   //
   if (k - 1 < 10)
      fw1.set(1);
   else
      fw1.set(2);
   // ---
   // 20 May 00
   //
   // CC on count at ucsc complains about the following:
   //
   //    ostrstream   oss[n];
   //    char*        p[n];
   assert(n > 0);
   oss = new ostrstream [n];
   p = new char* [n];
   for (i = 0; i < NCCS; ++i) {
      oss[i] << "   "
             << "t.c_cc[" << fw1 << i << "] = "
             << fw2 << (int) t.c_cc[i] << " = "
             << repr[t.c_cc[i]]
             << ends;
   }
   if (n > NCCS)
      oss[NCCS] << "" << ends;
   for (i = 0; i < n; ++i)
      p[i] = oss[i].str();
   //
   // Do not write gratuitous blanks at the end of the line.
   //
   assert(n == 2 * k);
   for (i = 0; i < k; ++i) {
      cout << p[i] << ((i < k - 1) ? "  " : "") << p[i + k] << "\n";
      delete [] p[i];
      delete [] p[i + k];
   }
   delete [] oss;
   delete [] p;
   cout << "\n"
           "After the bits have been set, we will have\n"
           "\n"
           "   t.c_cc[VMIN] = 1 = " << repr[1] << "\n"
           "\n"
           "[[What does this do for the program?]]\n"
           "\n";
   //
   // A fair amount has been printed, so we want to
   // give the user a chance to read it before
   // printing the heading proper.
   //
   // If the output has been redirected,
   // we exit here, in the else part.
   //
   if (isatty(1)) {
      cout << "Are you ready to continue? ";
      cin.getline(line, maxline);
      cout << "\n";
      istrstream   iss(line);
      iss >> answer;
      //
      // A carraige return means yes.
      //
      if (iss && *answer != 'y' && *answer != 'Y') {
         cout << "Bye!\n\n";
         exit(1);
      }
   }
   else {
      cout << "Bye!\n\n";
      exit(1);
   }
}

void wrt_help(cchr* pgm_name)
{
   cout << "---\n"
           "Usage:  " << pgm_name << " [-ahrt] [-wa] [-we]\n"
           "\n"
           "This program writes char values on the screen.\n"
           "\n"
           "---\n"
           "Options:\n"
           "   -a   alternate input option, enter integers instead\n"
           "   -e   write everything option, the same as -we\n"
           "   -h   help option, print this message\n"
           "   -r   rationale option, print more information\n"
           "   -t   test option, help for the programmer\n"
           "   -wa  write all names option, write a dictionary of names\n"
           "   -we  write everything option, run through all chars\n"
           " \n";
}

void wrt_msg_to_user()
{
   if (o.keyboard_option()) {
      cout << "---\n"
              "TO EXIT: Repeat a character three times.\n"
              "\n"
              "The keyboard is hot.\n"
              "                ---\n"
              "\n";
   }
   else if (o.alt_input_option()) {
      cout << "---\n"
              "ALTERNATE INPUT OPTION:\n"
              "\n"
              "The keyboard is hot.\n"
              "                ---\n"
              "\n"
              "Input integer values between 0 and 255.\n"
              "\n";
   }
}

void wrt_rationale(cchr* pgm_name)
{
   cchr*&   pg = pgm_name;

   cout << "===\n"
           "RATIONALE OPTION:\n"
           "\n"
           "We are trying to get at char values in different ways:\n"
           "\n"
           "   via the keyboard\n"
           "   via integer values typed on the keyboard\n"
           "   via running through all possible char values\n"
           "\n"
           "The options provided by this program achieve our objectives,\n"
           "although the program is somewhat delicate.  If we give the\n"
           "command\n"
           "\n"
           "   " << pg << "\n"
           "\n"
           "then the char values above 127 cannot be input.  If we give\n"
           "the command\n"
           "\n"
           "   " << pg << " -e > out\n"
           "\n"
           "then with the following two commands the nonascii latin1\n"
           "chars appear differently on the screen:\n"
           "\n"
           "   cat out         and         vi out\n"
           "\n"
           "---\n"
           "CAUTION:\n"
           "\n"
           "On some systems [maybe all], the following command will leave\n"
           "the xterm window in a bad state:\n"
           "\n"
           "   " << pg << " | more\n"
           "\n"
           "The reset command may restore the window, but on some systems\n"
           "the restoration is not equivalent to the original settings.\n"
           "To see this, give the following commands:\n"
           "\n"
           "   stty -g > save1\n"
           "   reset\n"
           "   " << pg << " | more\n"
           "   stty -g > save2\n"
           "   diff save[12]\n"
           "\n"
           "We would like to prevent the user from piping the output of this\n"
           "program, but with isatty() we cannot distinguish between a pipe\n"
           "and redirecting the output, and we definitely want the user\n"
           "to be able to redirect the output.\n"
           "\n"
           "---\n"
           "DELICATE\n"
           "\n"
           "This program is delicate in the sense that what one sees on the\n"
           "screen varies with the both the command and the system.  Getting\n"
           "it all to line up properly seems to be a Herculean task.\n"
           "Consider the following commands:\n"
           "\n"
           "   wrt_char -e\n"
           "   wrt_char -e > out\n"
           "   wrt_char -e | more\n"
           "\n"
           "Piping through more on a Sun SparcStation 10 running Solaris 7\n"
           "causes lines like the following to be printed on the screen\n"
           "[[according to Peter Scott, this is not the case on his\n"
           "linux machine]]:\n"
           "\n"
           "   M-^^   158   9e   236         10011110   0   0   0   .....\n"
           "   M-^_   159   9f   237         10011111   0   0   0   .....\n"
           "   M-    160   a0   240         10100000   0   0   0   .....\n"
           "   M-!   161   a1   241         10100001   0   0   0   .....\n"
           "\n"
           "I would like to make this output line up properly, but here is the\n"
           "problem.  Although the more utility sees a single character, if that\n"
           "character is in the range 128 to 255, what gets printed on the screen\n"
           "is M-?? where ?? is either one or two characters.  This conflicts with\n"
           "what happens on redirection.  In that case, when viewed with vi, we\n"
           "see \\200, \\201, etc.  These are all four characters each, so lining\n"
           "things up is not a problem.\n"
           "\n"
           "In an attempt [probably vain] to keep the user from piping the\n"
           "output through more, we provide that functionality ourselves.\n"
           "\n"
           "---\n"
           "MORE TO BE DONE:\n"
           "\n"
           "Because of the wide headings, this program requires an xterm\n"
           "window with at least " << mnc << " columns.  To test for the number of\n"
           "columns in the current xterm window, we execute the resize\n"
           "command via a system() call within the program.  Surely there\n"
           "is a way to do this directly via some C++ function call, but\n"
           "so far we have not been able to discover the secret.\n"
           "\n";
}
