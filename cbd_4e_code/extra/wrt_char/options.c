#include "wrt_char.h"

options::options()
{
   local_pgm_nm       = NULL;
   pgm_nm             = NULL;
   o_cnt              = 0;
   fwai               = -1;                    // first working arg index
   nwacl              = -1;             // # of working args on cmnd line
   help_opt           = off;
   //
   // The next two have
   // opposite values.
   //
   keyboard_opt       = on;
   alt_input_opt      = off;
   rationale_opt      = off;
   test_opt           = off;
   wrt_all_names_opt  = off;
   wrt_everything_opt = off;
   o_cnt = 1;
}

// ---
// If pgm_nm has a / in it, as in the following example,
// pick of the name following the last slash character.
//
//    /export/local/bin/ad
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
   cchr*   fct_name = "options::get_options()";

   cchr*   p;
   int     i;

   pgm_nm = argv[0];
   get_local_pgm_nm();
   for (i = 1; i < argc && *argv[i] == '-'; ++i) {
      for (p = argv[i] + 1; *p != '\0'; ++p) {
         switch (*p) {
         case 'a':
            //
            // The next two have
            // opposite values.
            //
            alt_input_opt = on;
            keyboard_opt = off;
            // ++o_cnt;
            break;
         case 'e':
            //
            // Equivalent to the wrt_everything option.
            //
            wrt_everything_opt = on;
            ++o_cnt;
            break;
         case 'h':
            help_opt = on;
            ++o_cnt;
            break;
         case 'n':
            wrt_all_names_opt = on;
            ++o_cnt;
            break;
         case 'r':
            rationale_opt = on;
            ++o_cnt;
            break;
         case 't':
            test_opt = on;
            ++o_cnt;
            break;
         case 'w':
            if (strncmp(p, "wa", 2) == 0)
               wrt_all_names_opt = on;
            else if (strncmp(p, "we", 2) == 0)
               wrt_everything_opt = on;
            else {
               cout << "---\n"
                       "ERROR: Unknown option.\n"
                       "\n";
               wrt_help(pgm_nm);
               exit(1);
            }
            p += 1;                         // p points at the last char
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
      off_on&   key = keyboard_opt;
      off_on&   alt = alt_input_opt;
      off_on&   tes = test_opt;
      off_on&   wan = wrt_all_names_opt;
      off_on&   weo = wrt_everything_opt;
      cout
      << "---\n"
         "TEST OPTION:\n"
         "\n"
         "         local_pgm_nm = " << l_pgm_nm    << "\n"
         "               pgm_nm = " << pgm_nm      << "\n"
         "                o_cnt = " << o_cnt       << "\n"
         "                 argc = " << argc        << "\n"
         "                 fwai = " << fwai        << "\n"
         "                nwacl = " << nwacl       << "\n"
         "             help_opt = " << report(hel) << "\n"
         "         keyboard_opt = " << report(key) << "\n"
         "        alt_input_opt = " << report(alt) << "\n"
         "             test_opt = " << report(tes) << "\n"
         "    wrt_all_names_opt = " << report(wan) << "\n"
         "   wrt_everything_opt = " << report(weo) << "\n"
         "\n";
   }
   //
   // Check two options.
   //
   switch(keyboard_opt) {
   case off:
      assert(alt_input_opt == on);
      break;
   case on:
      assert(alt_input_opt == off);
      break;
   default:
      error_exit_cannot_get_here(fct_name);
   }
   if (nwacl > 0) {
      cout << "---\n"
              "ERROR: This program takes no command line arguments.\n"
              "\n";
      wrt_help(pgm_nm);
      exit(1);
   }
   if (help_opt == on || rationale_opt == on || wrt_all_names_opt == on) {
      if (help_opt == on)
         wrt_help(pgm_nm);
      if (rationale_opt == on)
         wrt_rationale(pgm_nm);
      if (wrt_all_names_opt == on)
         wrt_all_names();
      exit(1);
   }
   if (wrt_everything_opt == on && alt_input_opt == on) {
      cout << "---\n"
              "ERROR: The two options -a and -we cannot both be on.\n"
              "\n";
      exit(1);
   }
}
