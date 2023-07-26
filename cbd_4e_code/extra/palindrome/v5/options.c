#include "palindrome.h"

options::options()
{
   local_pgm_nm = NULL;
   pgm_nm       = NULL;
   o_cnt        = 0;
   fwai         = -1;                          // first working arg index
   nwacl        = -1;                   // # of working args on cmnd line
   help_opt     = off;
   test_opt     = off;
}

// ---
// If pgm_nm has a / in it, as in the following example,
// pick of the name following the last slash character.
//
//    /export/local/bin/pgm
//

void options::get_local_pgm_nm()
{
   cchr*   p;
 
   p = pgm_nm + strlen(pgm_nm);
   for ( --p; p > pgm_nm && *p != '/'; --p)
      ;
   if (*p == '/')
      ++p;
   local_pgm_nm = new char [strlen(p) + 1];
   strcpy(local_pgm_nm, p);
}

void options::get_options(int argc, char** argv)
{
   cchr*   p;
   int     i;

   pgm_nm = argv[0];
   get_local_pgm_nm();
   for (i = 1; i < argc && *argv[i] == '-'; ++i) {
      for (p = argv[i] + 1; *p != '\0'; ++p) {
         switch (*p) {
         case 'h':
            help_opt = on;
            ++o_cnt;
            break;
         case 't':
            test_opt = on;
            ++o_cnt;
            break;
         default:
            cout << "---\n"
                    "ERROR: Unknown option.\n"
                    "\n";
            wrt_help(pgm_nm);
            exit(1);
         }
      }
   }
   fwai = i;
   nwacl = argc - fwai;
   assert(nwacl >= 0 && nwacl < argc);
   if (test_opt == on) {
      char*&    l_pgm_nm = local_pgm_nm;
      off_on&   hel = help_opt;
      off_on&   tes = test_opt;
      cout
      << "---\n"
         "TEST OPTION FOR PROGRAMMER:\n"
         "\n"
         "   local_pgm_nm = " << l_pgm_nm    << "\n"
         "         pgm_nm = " << pgm_nm      << "\n"
         "          o_cnt = " << o_cnt       << "\n"
         "           argc = " << argc        << "\n"
         "           fwai = " << fwai        << "\n"
         "          nwacl = " << nwacl       << "\n"
         "       help_opt = " << report(hel) << "\n"
         "       test_opt = " << report(tes) << "\n"
         "\n";
   }
   if (help_opt == on || nwacl == 0) {
      wrt_help(pgm_nm);
      exit(1);
   }
   if (nwacl > 1)
      error_exit_too_many_filenames();
}
