// ---
// Using partial pivoting, we compute the lu decomposition
// of the matrix a, if it exists.  Permutations are
// recorded in the permutation vector pv.
//

#include "lu_decomp.h"

no_yes lu_decomp(matrix a, matrix lu, ivec pv)
{
   int   i;
   int   j;
   int   k;
   int   n;
   int   r;
   dbl   d;
   dbl   m;
   dbl   val;
   dbl   tmp;

   n = a.row_size();
   assert(n == a.col_size());
   //
   // Begin by copying a into lu.
   //
   lu = a;
   //
   // Use the index k to run down the
   // diagonal of the lu matrix.
   //
   for (k = 1; k <= n; ++k) {
      //
      // The pivot is the element on or below the diagonal
      // which is the largest in absolute value.  Find the
      // index r corresponding to the pivot.
      //
      val = fabs(lu[k][k]);
      r = k;
      for (i = k + 1; i <= n; ++i) {
         if ((tmp = fabs(lu[i][k])) > val) {
            val = tmp;
            r = i;
         }
      }
      //
      // If val is zero, no LU decomposition exits.
      //
      if (val < 0.00001)
         return no;
      //
      // Store the permutation.
      //
      pv[k] = r;
      //
      // If the pivot is not in the current row, swap part
      // of the current row with part of the pivot row.
      //
      if (r != k) {
         for (j = k; j <= n; ++j) {
            tmp = lu[k][j];
            lu[k][j] = lu[r][j];
            lu[r][j] = tmp;
         }
      }
      //
      // The inverse of the pivot element is the diagonal
      // element of the eta matrix that is being computed.
      //
      d = lu[k][k] = 1.0 / lu[k][k];
      //
      // Multiply the remaining elements in the pivot row.
      //
      for (j = k + 1; j <= n; ++j)
         lu[k][j] *= d;
      //
      // First store the eta column entry.  Then effect the
      // action of the gauss transform by subtracting a
      // multiple of part of the kth row from
      // part of the ith row.
      //
      for (i = k + 1; i <= n; ++i) {
         m = lu[i][k];                                   // m is the multiplier
         if (m != 0.0) {
            lu[i][k] *= -d;                       // store the eta column entry
            for (j = k + 1; j <= n; ++j)       // action of the gauss transform
               lu[i][j] -= m * lu[k][j];
         }
      }
   }
   return yes;
}
