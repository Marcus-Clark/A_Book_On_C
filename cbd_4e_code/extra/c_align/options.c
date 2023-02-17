#include "c_align.h"

options::options()
{
   pgm_nm = NULL;
   o_cnt = 0;
   fwai = -1;
   nwacl = -1;
   re = default_right_edge;
   sty = none;
   force_opt = off;
   help_opt = off;
   right_edge_opt = off;
   style_opt = off;
   test_opt = off;
}

void options::get_options(int argc, char** argv)
{
   char*   p;
   char*   q;
   int     i;
   int     n;

   pgm_nm = argv[0];
   for (i = 1; i < argc && *argv[i] == '-'; ++i) {
      for (p = argv[i] + 1; *p != '\0'; ++p) {
         switch (*p) {
         case 'f':
            force_opt = on;
            ++o_cnt;
            break;
         case 'h':
            help_opt = on;
            ++o_cnt;
            break;
         case 'r':
            //
            // Two possibilities for placement:
            //
            //    -r57
            //    -r 57
            //
            q = p + 1;
            if (*q != '\0') {
               //
               // The right edge value is adjacent.
               //
               n = store_right_edge(q);
               p += n;                           // p points at last char
            }
            else {
               //
               // The next argument is the right edge value.
               //
               p = argv[++i];
               if (i >= argc)
                  error_exit_right_edge_not_found();
               n = store_right_edge(p);
               p += n - 1;                       // p points at last char
            }
            right_edge_opt = on;
            ++o_cnt;
            break;
         case 's':
            //
            // Two possibilities for placement:
            //
            //    -sc++
            //    -s c++
            //
            // The possible styles are c and c++.
            //
            q = p + 1;
            if (*q != '\0') {
               //
               // The style is adjacent.
               //
               n = store_style(q);
               p += n;                           // p points at last char
            }
            else {
               //
               // The next argument is the style.
               //
               p = argv[++i];
               if (i >= argc)
                  error_exit_style_not_found();
               n = store_style(p);
               p += n - 1;                       // p points at last char
            }
            style_opt = on;
            ++o_cnt;
            break;
         case 't':
            test_opt = on;
            ++o_cnt;
            break;
         default:
            cout << "ERROR: Unknown option:\n"
                    "\n"
                    "   argv[" << i << "] = " << argv[i] << "\n"
                    "   p = " << p << "\n"
                    "\n";
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
      off_on&   fce = force_opt;
      off_on&   hlp = help_opt;
      off_on&   red = right_edge_opt;
      off_on&   ste = style_opt;
      off_on&   tst = test_opt;
      cout << "---\n"
              "TEST OPTION: " << "\n"
              "\n"
              "           pgm_nm = " << pgm_nm      << "\n"
              "            o_cnt = " << o_cnt       << "\n"
              "             argc = " << argc        << "\n"
              "             fwai = " << fwai        << "\n"
              "            nwacl = " << nwacl       << "\n"
              "        force_opt = " << report(fce) << "\n"
              "         help_opt = " << report(hlp) << "\n"
              "   right_edge_opt = " << report(red) << "\n";
   if (right_edge_opt == on)
      cout << "               re = " << re          << "\n";
      cout << "        style_opt = " << report(ste) << "\n";
   if (style_opt == on)
      cout << "              sty = " << report(sty) << "\n";
      cout << "         test_opt = " << report(tst) << "\n"
              "\n";


   }
   if (help_opt == on) {
      wrt_help(pgm_nm);
      exit(1);
   }
   if (test_opt == off && nwacl == 0) {
      wrt_help(pgm_nm);
      exit(1);
   }
}

int options::store_right_edge(cchr* s)
{
   int          n;
   istrstream   iss(s);

   assert(re == default_right_edge);
   iss >> re;
   if (!iss)
      error_exit_right_edge_not_found(s);
   if (re < 1)
      error_exit_positive_integer_required(re);
   right_edge = re;
   n = strlen(s);
   return n;
}

int options::store_style(cchr* s)
{
   int          n;
   istrstream   iss(s);

   assert(sty == none);
   if (strcmp(s, "c++") == 0)
      sty = cpp;
   else if (strcmp(s, "c") == 0)
      sty = c;
   else
      error_exit_style_not_found(s);
   n = strlen(s);
   return n;
}
