#include "mk_cols.h"

ostream& operator<<(ostream& os, matrix a)
{
   int*   fw;                                              // field width
   int    i;
   int    j;
   int    len;

   int    ind = o.get_indent();                            // indentation
   int    m   = a.row_size();
   int    n   = a.col_size();

   assert(os);
   assert(m > 0 && n > 0);
   assert(n == o.get_ncols());
   //
   // Create an array of field widths.
   //
   fw = (new int [n]) - 1;                         // index from 1, not 0
   //
   // Initialize the array to zero.
   //
   for (j = 1; j <= n; ++j)
      fw[j] = 0;
   //
   // CAUTION:
   //    The last row of the matrix
   //    may contain NULL pointers.
   //
   for (j = 1; j <= n; ++j) {
      for (i = 1; i <= m; ++i) {
         if (a[i][j] != NULL) {
            len = strlen(a[i][j]);
            if (len > fw[j])
               fw[j] = len;
         }
      }
   }
   mk_adjustments(fw, n);
   // wrt_fw(fw, n);                                        // debug only
   os.setf(ios::left);
   for (i = 1; i <= m; ++i) {
      cout << setw(ind) << "";
      for (j = 1; j <= n; ++j) {
         if (a[i][j] != NULL) {
            if (j == n || a[i][j + 1] == NULL)
               os << a[i][j];
            else
               os << setw(fw[j]) << a[i][j];
         }
         // else                                                 // debug
         //    os << setw(fw[j]) << "(null)";
      }
      os << "\n";
   }
   os.unsetf(ios::left);
   return os;
}
