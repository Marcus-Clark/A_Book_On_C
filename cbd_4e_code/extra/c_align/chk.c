// ---
// Check file access, and if the force option
// is not on, check filename extentsions.
//
// See the top of main.c for allowable
// filename extensions.
//

#include "c_align.h"

void chk_filenames(int argc, char** argv)
{
   cchr*       p;
   int         i;
   int         j;
   int         sz;
   fname_ext   e;

   int         fwai = o.get_fwai();            // first working arg index

   //
   // Check file access.
   //
   for (i = fwai; i < argc; ++i) {
      if (access(argv[i], R_OK | W_OK) != 0)
         error_exit_cannot_access(argv[i]);
   }
   //
   // Check filename extensions.
   //
   if (!o.force_option()) {
      sz = e.size();
      for (i = fwai; i < argc; ++i) {
         p = strrchr(argv[i], '.');
         if (p == NULL)
            error_exit_filename_ext_not_found(argv[i]);
         for (j = 0; j < sz; ++j) {
            if (strcmp(p, e[j]) == 0)
               break;
         }
         if (j == sz)
            error_exit_wrong_filename_ext(argv[i]);
      }
   }
}
