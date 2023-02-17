#include "mk_cols.h"

options::options()
{
   local_pgm_nm = NULL;
   pgm_nm = NULL;
   o_cnt = 0;
   fwai = -1;                                  // first working arg index
   nwacl = -1;                          // # of working args on cmnd line
   indent = -1;
   ncols = -1;
   alphabetize_opt = off;
   help_opt = off;
   indent_opt = off;
   ncols_opt = off;
   space_opt = off;
   uppercase_opt = off;
   test_opt = off;
   width_opt = off;
   width = default_screen_width;
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
   cchr*   p;
   cchr*   q;
   int     i;
   int     n;
   int     start;

   pgm_nm = argv[0];
   get_local_pgm_nm();
   if (argc > 1 && isdigit(*argv[1])) {
      set_ncols(argv[1]);
      start = 2;
   }
   else
      start = 1;
   for (i = start; i < argc && *argv[i] == '-'; ++i) {
      for (p = argv[i] + 1; *p != '\0'; ++p) {
         switch (*p) {
         case 'a':
            alphabetize_opt = on;
            ++o_cnt;
            break;
         case 'h':
            help_opt = on;
            ++o_cnt;
            break;
         case 'i':
            //
            // Two possibilities for the indentation:
            //
            //    -i7
            //    -i 7
            //
            q = p + 1;
            if (*q != '\0') {
               //
               // The indent value is adjacent.
               //
               n = store_indent(q);
               p += n;                           // p points at last char
            }
            else {
               //
               // The next argument is the indent value.
               //
               p = argv[++i];
               if (i >= argc)
                  error_exit_indent_not_found();
               n = store_indent(p);
               p += n - 1;                       // p points at last char
            }
            indent_opt = on;
            ++o_cnt;
            break;
         case 's':
            //
            // Two possibilities for placement:
            //
            //    -s7
            //    -s 7
            //
            q = p + 1;
            if (*q != '\0') {
               //
               // The space value is adjacent.
               //
               n = store_space(q);
               p += n;                           // p points at last char
            }
            else {
               //
               // The next argument is the space value.
               //
               p = argv[++i];
               if (i >= argc)
                  error_exit_space_not_found();
               n = store_space(p);
               p += n - 1;                       // p points at last char
            }
            space_opt = on;
            ++o_cnt;
            break;
         case 't':
            test_opt = on;
            ++o_cnt;
            break;
         case 'u':
            uppercase_opt = on;
            ++o_cnt;
            break;
         case 'w':
            //
            // Two possibilities for placement:
            //
            //    -w57
            //    -w 57
            //
            q = p + 1;
            if (*q != '\0') {
               //
               // The width value is adjacent.
               //
               n = store_width(q);
               p += n;                           // p points at last char
            }
            else {
               //
               // The next argument is the width value.
               //
               p = argv[++i];
               if (i >= argc)
                  error_exit_width_not_found();
               n = store_width(p);
               p += n - 1;                       // p points at last char
            }
            width_opt = on;
            ++o_cnt;
            break;
         default:
            if (isdigit(*p)) {
               if (ncols != -1)
                  whoops_exit_too_many_ncols_specified();
               ncols_opt = on;
               ++o_cnt;
               q = p + 1;
               while (isdigit(*q))
                  ++q;
               if (*q != '\0')
                  error_exit_ncols_not_found(p);
               istrstream   iss(p);
               iss >> ncols;
               if (!iss)
                  error_exit_ncols_not_found(p);
               if (ncols < 1)
                  error_exit_ncols_must_be_positive(ncols, p);
               n = strlen(p);
               p += n - 1;                      // point at the last char
            }
            else {
               cout << "---\n"
                       "ERROR: Unknown option - bye!\n\n";
               wrt_help(pgm_nm);
               exit(1);
            }
         }
      }
   }
   //
   // Capture the first working arg index.
   //
   fwai = i;
   nwacl = argc - fwai;
   if (test_opt == on) {
      off_on&   abt = alphabetize_opt;
      off_on&   hlp = help_opt;
      off_on&   ind = indent_opt;
      off_on&   nco = ncols_opt;
      off_on&   tst = test_opt;
      off_on&   upc = uppercase_opt;
      off_on&   wdh = width_opt;
      cout << "---\n"
              "TEST OPTION:\n"
              "\n"
              "      local_pgm_nm = " << local_pgm_nm << "\n"
              "            pgm_nm = " << pgm_nm << "\n"
              "             o_cnt = " << o_cnt << "\n"
              "              argc = " << argc << "\n"
              "              fwai = " << fwai << "\n"
              "             ncols = " << ncols << "\n"
              "             nwacl = " << nwacl << "\n"
              "             width = " << width << "\n"
              "   alphabetize_opt = " << report(abt) << "\n"
              "          help_opt = " << report(hlp) << "\n"
              "        indent_opt = " << report(ind) << "\n"
              "         ncols_opt = " << report(nco) << "\n"
              "          test_opt = " << report(tst) << "\n"
              "     uppercase_opt = " << report(upc) << "\n"
              "         width_opt = " << report(wdh) << "\n"
              "\n";
      exit(1);
   }
   if (help_opt == on || argc == 1) {
      wrt_help(pgm_nm);
      exit(1);
   }
   if (nwacl > 1)
      error_exit_too_many_cmnd_line_args();
   if (ncols == -1)
      whoops_exit_ncols_not_specified();
}

void options::set_ncols(cchr* s)
{
   cchr*   p;

   if (ncols != -1)
      whoops_exit_too_many_ncols_specified();
   for (p = s; isdigit(*p); ++p)
      ;
   if (*p != '\0')
      error_exit_ncols_not_found(s);
   istrstream   iss(s);
   iss >> ncols;
   if (!iss)
      error_exit_ncols_not_found(s);
   if (ncols < 1)
      error_exit_ncols_must_be_positive(ncols, s);
}

int options::store_indent(cchr* s)
{
   int          n;
   istrstream   iss(s);

   iss >> indent;
   if (!iss)
      error_exit_indent_not_found(s);
   if (indent < 0)
      error_exit_nonnegative_integer_required(space);
   n = strlen(s);
   return n;
}

int options::store_space(cchr* s)
{
   int          n;
   istrstream   iss(s);

   iss >> space;
   if (!iss)
      error_exit_space_not_found(s);
   if (space < 0)
      error_exit_nonnegative_integer_required(space);
   n = strlen(s);
   return n;
}

int options::store_width(cchr* s)
{
   int          n;
   istrstream   iss(s);

   assert(width == default_screen_width);
   iss >> width;
   if (!iss)
      error_exit_width_not_found(s);
   if (width < 1)
      error_exit_positive_integer_required(width);
   n = strlen(s);
   return n;
}
