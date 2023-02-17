#include "fortune.h"

options::options()
{
   pgm_nm = NULL;
   uc_pgm_nm = NULL;
   o_cnt = 0;
   ffi = 0;
   help_opt = off;
   help_help_opt = off;
   help_help_help_opt = off;
   test_opt = off;
}

void options::get_options(int argc, char** argv)
{
   char*     p;
   cchr*     q;
   int       i;
   int       nonoption_argc = 0;
   off_on&   hho = help_help_opt;

   cout << "\n";
   pgm_nm = argv[0];
   uc_pgm_nm = new char [strlen(pgm_nm) + 1];
   strcpy(uc_pgm_nm, pgm_nm);
   for (p = uc_pgm_nm; *p != '\0'; ++p)
      *p = toupper(*p);
   for (i = 1; i < argc; ++i)
      if (*argv[i] != '-')
         ++nonoption_argc;
   for (i = 1; i < argc && *argv[i] == '-'; ++i) {
      for (q = argv[i] + 1; *q != '\0'; ++q) {
         switch (*q) {
         case 'h':
            if (*(q + 1) == 'h' && *(q + 2) == 'h') {
                help_help_help_opt = on;
               q += 2;                          // point at the last h in "hhh"
            }
            else if (*(q + 1) == 'h') {
               help_help_opt = on;
               ++q;                            // point at the second h in "hh"
            }
            else
               help_opt = on;
            ++o_cnt;
            break;
         case 't':
            test_opt = on;
            ++o_cnt;
            break;
         default:
            cout << "ERROR: Unknown option.\n\n";
            prn_info(pgm_nm);
            exit(1);
         }
      }
   }
   //
   // Capture the first file index.
   //
   ffi = i;
   if (test_opt == on) {
      cout
      << "---\n"
         "TEST OPTION:\n"
         "          pgm_nm = " << pgm_nm                             << "\n"
         "           o_cnt = " << o_cnt                              << "\n"
         "            argc = " << argc                               << "\n"
         "             ffi = " << ffi                                << "\n"
         "        help_opt = " << ((help_opt == off) ? "off" : "on") << "\n"
         "   help_help_opt = " << ((hho == off) ? "off" : "on")      << "\n"
         "        test_opt = " << ((test_opt == off) ? "off" : "on") << "\n"
         "\n";
   }
   if (help_help_help_opt == on) {
      prn_much_more_info();
      exit(1);
   }
   if (help_help_opt == on) {
      prn_more_info(pgm_nm);
      exit(1);
   }
   if (ffi != argc || help_opt == on) {
      prn_info(pgm_nm);
      exit(1);
   }
}
