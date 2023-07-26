#include "lu_decomp.h"

options::options()
{
   fn = NULL;
   pgm_nm = NULL;
   o_cnt = 0;
   prec = 1;                                                   // default value
   fwai = -1;
   nwacl = -1;
   file_opt = off;
   help_opt = off;
   norm_only_opt = off;
   time_opt = off;
   verbose_opt = off;
}

void options::get_options(int argc, char** argv)
{
   cchr*   p;
   cchr*   q;
   int     i;
   int     n;
   int     nonoption_argc = 0;

   cout << "\n";
   pgm_nm = argv[0];
   for (i = 1; i < argc; ++i)
      if (*argv[i] != '-')
         ++nonoption_argc;
   for (i = 1; i < argc && *argv[i] == '-'; ++i) {
      for (p = argv[i] + 1; *p != '\0'; ++p) {
         switch (*p) {
         case 'f':
            file_opt = on;
            ++o_cnt;
            q = p + 1;
            if (*q != '\0') {                           // filename is adjacent
               n = store_filename(q);
               p += n;                                 // p points at last char
            }
            else {                                 // filename is next argument
               ++i;
               if (i >= argc) {
                  cout << "ERROR: Filename following -f not found - bye!\n\n";
                  exit(1);
               }
               p = argv[i];
               n = store_filename(p);
               p += n - 1;                             // p points at last char
            }
            break;
         case 'h':
            help_opt = on;
            ++o_cnt;
            break;
         case 'n':
            norm_only_opt = on;
            ++o_cnt;
            break;
         case 'p':
            prec_opt = on;
            ++o_cnt;
            q = p + 1;
            if (*q != '\0') {                           // filename is adjacent
               n = store_precision(q);
               p += n;                                 // p points at last char
            }
            else {                                 // filename is next argument
               ++i;
               if (i >= argc) {
                  cout << "ERROR: Precision following -p not found - bye!\n\n";
                  exit(1);
               }
               p = argv[i];
               n = store_precision(p);
               p += n - 1;                             // p points at last char
            }
            break;
         case 't':
            if (strcmp(p, "time") == 0) {
               time_opt = on;
               p += 3;                                 // p points at last char
            }
            else
               test_opt = on;
            ++o_cnt;
            break;
         case 'v':
            verbose_opt = on;
            cout << "WHOOPS: Verbose option not implemented yet.\n\n";
            ++o_cnt;
            break;
         default:
            cout << "ERROR: Unknown option.\n\n";
            wrt_help(pgm_nm);
            exit(1);
         }
      }
   }
   //
   // Capture the first working arg index.
   //
   fwai = i;
   nwacl = argc - fwai;
   if (test_opt == on) {
      off_on&   fle = file_opt;
      off_on&   hlp = help_opt;
      off_on&   nmo = norm_only_opt;
      off_on&   prc = prec_opt;
      off_on&   tst = test_opt;
      off_on&   tim = time_opt;
      off_on&   vbs = verbose_opt;
      cout
      << "---\n"
         "TEST OPTION:\n"
         "              fn = " << fn          << "\n"
         "          pgm_nm = " << pgm_nm      << "\n"
         "           o_cnt = " << o_cnt       << "\n"
         "            argc = " << argc        << "\n"
         "            fwai = " << fwai        << "\n"
         "           nwacl = " << nwacl       << "\n"
         "        file_opt = " << report(fle) << "\n"
         "        help_opt = " << report(hlp) << "\n"
         "   norm_only_opt = " << report(nmo) << "\n"
         "        prec_opt = " << report(prc) << "\n"
         "        test_opt = " << report(tst) << "\n"
         "        time_opt = " << report(tim) << "\n"
         "     verbose_opt = " << report(vbs) << "\n"
         "\n";
      exit(1);
   }
   if (argc == 1 || help_opt == on) {
      wrt_help(pgm_nm);
      exit(1);
   }
   if (nwacl > 1) {
      cout << "ERROR: Too many arguments.\n\n";
      wrt_help(pgm_nm);
      exit(1);
   }
   if (nwacl < 1) {
      cout << "ERROR: n missing at the end of the command line.\n\n";
      wrt_help(pgm_nm);
      exit(1);
   }
}

cchr* options::report(off_on val)
{
   return ((val == off) ? "off" : "on");
}

int options::store_filename(cchr* s)
{
   int   n;

   if (isspace(*s)) {
      cout << "ERROR: Filename cannot start with "
              "a white space character - bye!\n\n";
      exit(1);
   }
   if (*s == '-') {
      cout << "ERROR: Filename cannot start with a hypen - bye!\n\n";
      exit(1);
   }
   n = strlen(s);
   fn = new char [n + 1];
   strcpy(fn, s);
   return n;
}

int options::store_precision(cchr* s)
{
   const char*   p;
   int           n;

   for (p = s; *p != '\0'; ++p) {
      if (!isdigit(*p)) {
         cout << "ERROR: Precision following -p not found - bye!\n\n";
         exit(1);
      }
   }
   n = strlen(s);
   istrstream   iss(s);
   iss >> prec;
   assert(iss);
   return n;
}
