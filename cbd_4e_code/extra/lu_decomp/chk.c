#include "lu_decomp.h"

dbl chk(matrix a, matrix lu, ivec pv)
{
   int      i;
   int      j;
   int      k;
   int      n = a.row_size();
   int      r;
   dbl      d;
   dbl      m;
   dbl      sum;
   dbl      tmp;
   dbl      val;
   matrix   diff(n, n);
   matrix   psy_l(n, n);
   matrix   u(n, n);

   assert(n == a.col_size());
   assert(n == lu.row_size());
   assert(n == lu.col_size());
   assert(n == pv.size());
   //
   // Start with the identity matrix and use lu and pv to create
   // the following psychologically lower triangular matrix:
   //
   //                  -1               -1
   //    psy_l = P  * L   * ... * P  * L
   //             1    1           n    n
   //
   psy_l.identity();
   for (k = n; k >= 1; --k) {
      //
      // Carry out the action of the inverse of L .
      //                                         k
      //
      d = 1.0 / lu[k][k];
      for (j = 1; j <= n; ++j)
         psy_l[k][j] *= d;
      for (i = k + 1; i <= n; ++i) {
         m = -lu[i][k];
         //
         // Remember:
         //    The factor d is already in
         //    the element psy_l[k][j].
         //
         for (j = 1; j <= n; ++j)
            psy_l[i][j] += m * psy_l[k][j];
      }
      //
      // Carry out the action of P .
      //                          k
      //
      if ((r = pv[k]) != k) {
         for (j = 1; j <= n; ++j) {
            tmp = psy_l[k][j];
            psy_l[k][j] = psy_l[r][j];
            psy_l[r][j] = tmp;
         }
      }
   }
   //
   // Create u from the lu matrix.
   //
   for (i = 1; i <= n; ++i) {
      for (j = 1; j <= n; ++j) {
         if (i == j)
            u[i][j] = 1.0;
         else if (i > j)
            u[i][j] = 0.0;
         else
            u[i][j] = lu[i][j];
      }
   }
   //
   // Compute the product psy_l * u and
   // find the following difference:
   //
   //    a - psy_l * u
   //
   for (i = 1; i <= n; ++i) {
      for (j = 1; j <= n; ++j) {
         sum = 0.0;
         for (k = 1; k <= n; ++k)
            sum += psy_l[i][k] * u[k][j];
         diff[i][j] = a[i][j] - sum;
      }
   }
   //
   // Compute the value of the norm of the difference,
   // release local working space, and return the
   // value.
   //
   val = diff.norm();
   diff.release_space();
   psy_l.release_space();
   u.release_space();
   return val;
}
