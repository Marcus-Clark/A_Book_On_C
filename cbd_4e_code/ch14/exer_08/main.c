#include "fortune.h"

const int   limit       = 5000000;                              // five million
const int   maxline     = 700;
const int   maxstring   = 200;
options     o;                                            // options are global

int main(int argc, char** argv)
{
   char     line[maxline];
   char     phrase[maxstring];
   int      n;
   no_yes   answer;

   o.get_options(argc, argv);
   if (o.test_option()) {
      cout << "---\n"
              "TEST OPTION:\n"
              "\n"
              "Fortunes will be found.\n"
              "For testing purposes, search for \"the\" "
              "or some other common phrase.\n"
              "\n"
              "Input a phrase to be searched for: ";
   }
   else {
      cout << "---\n"
              "THIS IS THE " << o.uc_pgm_name() << " PROGRAM:\n"
              "\n"
              "Fortunes will be found.\n"
              "\n"
              "Input a phrase to be searched for: ";
   }
   cin.getline(phrase, maxstring);
   if (!cin) {
      cout << "\nERROR: Phrase not found - bye!\n\n";
      exit(1);
   }
   cout << "\n"
           "How many fortunes containing this phrase do you want? ";
   n = get_int_reply(1, 100);
   cout << "\n"
           "            Phrase desired: " << phrase << "\n"
           "Number of fortunes desired: " << n << "\n"
           "\n"
           "Do you wish to continue? ";
   cin.getline(line, maxline);
   answer = get_answer(line);
   if (answer == no) {
      cout << "\nBye!\n\n";
      exit(1);
   }
   cout << "\n"
           "---\n"
           "SUGESTION:\n"
           "   The program is running, and it may\n"
           "   continue to run for many minutes.\n"
           "\n"
           "   Put it in background.\n"
           "\n";

   find_fortune(phrase, n);
}
