#include "lu_decomp.h"

ostream& operator<<(ostream& os, matrix a)
{
   int   fw;
   int   i;
   int   j;
   int   m = a.row_size();
   int   n = a.col_size();
   int   prec = o.precision();

   fw = 5 + prec;
   os.setf(ios::fixed);
   os.precision(prec);
   for (i = 1; i <= m; ++i) {
      for (j = 1; j <= n; ++j)
         os << setw(fw) << a[i][j];
      os << "\n";
   }
   return os;
}

ostream& operator<<(ostream& os, ivec pv)
{
   int   fw = 5 + o.precision();
   int   i;
   int   n = pv.size();

   for (i = 1; i <= n; ++i)
      os << setw(fw) << pv[i];
   return os;
}
